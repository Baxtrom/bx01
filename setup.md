# Full building process
> [!NOTE]
> _this page is mostly for my personal reference when setting up qmk for a custom build again, feel free to refer to it but there could be mistakes_

- [Layout, plate and case design](https://github.com/Baxtrom/bx01/blob/main/setup.md#layout-plate-and-case-design)
- [Qmk setup](https://github.com/Baxtrom/bx01/blob/main/setup.md#qmk-setup)
## Layout, plate and case design
_this can be done in many ways, this is just the way that worked for me_
### Tools needed
- Keyboard Layout Editor _(http://www.keyboard-layout-editor.com)_
- Plate and case buider _(http://builder.swillkb.com)_
- CAD software. [Fusion 360](https://www.autodesk.com/products/fusion-360/) would work best but im more comfortable with [Blender](https://www.blender.org/download/) and it does the job. 
### Layout 
I started by researching popular layouts, and found one to use as a staring point. In my case i landed on the cantor by beekeeb. I started by recreating the general layout in KLe


## Qmk setup
_Here are the steps i followed to setup my keyboard from start to finish_

### Software needed
- Code editor _(i reccomend VScode, https://code.visualstudio.com/download)_
- QMK MSYS _(https://msys.qmk.fm)_
- QMK toolbox _(https://github.com/qmk/qmk_toolbox/releases)_
- VIA (optional) _(https://github.com/the-via/releases/releases)_
_when downloading software from github make sure you choose the latest release and the right file type for your OS (download the .exe for windows)_

### Ressources 
- QMK docs _(https://docs.qmk.fm/#/)_
- QMK file docs _( ```qmk_firmware/docs``` either on the qmk github page or on your local install)_
- Youtube _(people such as joe scotto, jan lunge, datulab tech, djambo)_

### First setup
Open QMK MSYS and run ```qmk setup ```. Answer y to all questions. 

### Creating your keyboard file
Once that's done, run ```qmk new-keyboard```. Answer all questions with required info _(name, github username, real name)_. Then when asked to pick a base layout enter ```51``` _(none of the above)_  if you want to start from scratch _(which i'd reccomend to get comfortable with qmk)_. When asked for your microcontroller (MCU), enter the appropriate number _(it's important to get this right)_. I used a pro micro, which has an atmega32u4. Now your setup is good.

### Editing the files
Naviguate to the qmk firmware folder (should be in your user folder) ```C:\Users\<user>\qmk_firmware\keyboards```. Find and open the folder with the same name as your keyboard. Once open, go to the navigation bar up top and delete the file path and replace it with just ```cmd``` and hit enter. This will open the console. Now type ```code .```. This will open the folder in VScode where you can start editing files. ![CMD](https://github.com/Baxtrom/bx01/assets/152244482/36e02226-12c5-4411-b9b0-8c1d5301707b)  

#### Config.h, readme.md, rules.mk
These are used to enable certain features and provide documentation to others using your files, you won't really need to change these, but more info can be found in the qmk docs. 

#### Info.json 
This is where most of the information about your setup that qmk needs will be. Manufacturer, Keyboard name and maintainer can be changed to anything you want. Bootloader will usually need to be changed. Find the default bootloader for your micro-controller and replace the one in the file with it. _(For a pro micro it should be ```caterina```)_. The features section can be customized to your liking and is used to enable special features. The default will be good for most people. _(more info can be found [here](https://github.com/qmk/qmk_firmware/blob/834fb0b1fe47d20aac27eda39f165b96fe4ddaa6/docs/reference_info_json.md))_ The matrix pins will need to represent how you wired your matrix to your microcontroller. The pin lists go from left to right for collumns and top to bottom for rows. You can find the pin names for your microcontroller by searching the avr pinout of your board. The processor section should match the one on your microcontroller. Url can be left empty, and is usually used to insert the link to a product page. The usb section can be left as default, but you can change the version to anything you want, and the pid and vid (product and vendor id) can be changed by using an online text-to-hex converter. and converting two characters into a four character hex code, which you'll insert after the 0x. For example if i want the vid to be bx and the pid to be 01, i can convert them and insert them into the code as ```0x6278```and ```0x30331``` 

##### Layouts

This part will need to change to match your keyboard as the default is a numpad setup. First, change ```LAYOUT_ortho_4x4``` to something more simple like your keyboard name _(i personally just use ```LAYOUT```)_ then you'll want to input the "coordinates" for the location of all your keys. It'll help to make a keymap _(like i did [here](/Layout+Wiring/Wiring_Schematic.png))_. The standard format should be ```{"matrix": [<RowNumber>, <CollumnNumber>], "x": CollumnNumber, "y": RowNumber},``` _(Although its counterintuitive, the x and y in the brackets are in the reverse order, like shown)_. For example my layout looks like this (it has 5 collumns and 4 rows)
```
 "layouts": {
        "LAYOUT": {
            "layout": [


                {"matrix": [0, 0], "x": 0, "y": 0},
                {"matrix": [0, 1], "x": 1, "y": 0},
                {"matrix": [0, 2], "x": 2, "y": 0},
                {"matrix": [0, 3], "x": 3, "y": 0},
                {"matrix": [0, 4], "x": 4, "y": 0},



                {"matrix": [1, 0], "x": 0, "y": 1},
                {"matrix": [1, 1], "x": 1, "y": 1},
                {"matrix": [1, 2], "x": 2, "y": 1},
                {"matrix": [1, 3], "x": 3, "y": 1},
                {"matrix": [1, 4], "x": 4, "y": 1},

```
and so on.. for each row.

#### Keymap.c

You can locate this file in the ```keymaps``` folder and then ```default``` folder. Any text in green is used as a "comment" _(it's green in VScode, but you can also recognize comments by the slashes before them)_. You can delete these as they wont match your build. You now get to build your base/default layer. Your file should match this format:
```
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = <LAYOUT_name>(
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?
    )
};
```
This grid needs to match your layout you configured in info.json. Replace ```<LAYOUT_name>``` with the name of your layout you chose earlier in info.json. Separate the collumns with commas and rows with enter. Make sure the total number of keys matches your layout and the grid width and height, your collums and rows. Replace the keycodes _(KC_??)_ with those you want to use. These represent characters, actions or modifiers. A full list can be found [here](https://github.com/qmk/qmk_firmware/blob/834fb0b1fe47d20aac27eda39f165b96fe4ddaa6/docs/keycodes.md).

##### Layers
Layers allow you to have one key do different actions. You're gonna need to create a new layer. You can copy your base layer and paste it under. Now, change the number in the square brackets. It should follow this format:

```
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

      [0] = <LAYOUT_name>(
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_MO(1)
      [1] = <LAYOUT_name>(
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_?,
        KC_?,   KC_?,   KC_?,   KC_TRNS 
  };
```
Next, choose which key you want to use to switch layers. You need to replace it's keycode with ```MO(<layer number>)``` _(like shown in the bottom right key  in the code above)_. This key will now switch to the layer indicated, while you hold the key. There are a few keycodes for changing layers _(to toggle a layer, etc...)_. You can explore the options on the [keycode page](https://github.com/qmk/qmk_firmware/blob/834fb0b1fe47d20aac27eda39f165b96fe4ddaa6/docs/keycodes.md). Once you have decided on a key, you will need to replace the keycode of the matching key _(in the indicated layer)_ with ```KC_TRNS```, which will make it transparent, so that the layer switch key is still registered by the keyboard _(demonstrated above)_. You can also use this key to avoid retyping keys that are persistent throughout your layers, as keypresses will register as the next lowest layer that doesn't have ```KC_TRNS```. You can add as many layers as you want _(up to 15)_, just make sure to place ```KC_TRNS``` "over" the layer keycode on the destination layer. After editing, make sure you save all files you changed (In VScode, head into the file menu in the top bar, and press ```Save all```

### Via Setup (optional) _[skip ahead](https://github.com/Baxtrom/bx01/blob/main/setup.md#compiling-and-flashing-firmware)_
Via will allow you to have a visual interface that allows you to remap keys on-the-fly, as well as toggling layout options, programming macros, and controlling lighting. This will save you time editing code and reflashing your board _(which i'll explain later)_ 

First you will need to create a new folder for via under ```\qmk_firmware\keyboards\<keyboard_name>\keymaps\```. Either make a blank folder name "via", where you will need to copy and paste the ```config.h```, ```keymap.c```, ```rules.mk``` files you worked on earlier. The other option is to copy ```keymaps/default```, rename it to "via" and add the other two files. The folder should be organized like this: _(ignore ```via.json```, we'll come back to it in a bit)_
![image](https://github.com/Baxtrom/bx01/assets/152244482/5537ac34-abde-4679-a838-adea1821b70c)

Now go to rules.mk and add this line ```VIA_ENABLE = yes```. Make sure yes is all lowercase.  Now, you will need to go to [keyboard layout editor] (http://www.keyboard-layout-editor.com). Either load your previously made layout, or make your layout. Once all the keys are placed, you will need to match all the keys with their matrix "coordinates" that you set up earlier _(the ones in the square brackets)_. Place each key's coordinate in the left "top legend". On my board it looked like this:

![image](https://github.com/Baxtrom/bx01/assets/152244482/fed11210-0028-4e87-886a-35a62165020f)

Now go to the raw data tab of KLE and copy the code. 

#### via.json
You will now need to create a new file in your code editor, named ```via.json``` and save it under the ```via``` folder _(like shown previously)_. Now copy this into it:
```
{
    "name": "?",
    "vendorId": "0x?",
    "productId": "0x?",
    "matrix": {"rows": ?, "cols": ? },  //these numbers represent height and width of your keyboard matrix
    "layouts" : {
        "keymap": [
            //PASTE KLE LAYOUT HERE
        ]
    }
}
```
Replace the question marks with the appropriate info_(and delete the comments)_. Match what you used in the rest of the setup. Once done, mine looked like this:
```
{
    "name": "bx01",
    "vendorId": "0x4258",
    "productId": "0x3031",
    "matrix": {"rows": 4, "cols": 5 },
    "layouts" : {
        "keymap": [
            ["0,0",{"x":1},"0,2"],
            [{"y":-0.75,"x":1},"0,1",{"x":1},"0,3"],
            [{"y":-0.75,"x":4},"0,4"],
            [{"y":-0.5},"1,0",{"x":1},"1,2"],
            [{"y":-0.75,"x":1},"1,1",{"x":1},"1,3"],
            [{"y":-0.75,"x":4},"1,4"],
            [{"y":-0.5},"2,0",{"x":1},"2,2"],
            [{"y":-0.75,"x":1},"2,1",{"x":1},"2,3"],
            [{"y":-0.75,"x":4},"2,4"],
            [{"y":-0.5},"3,0"],
            [{"y":-0.5,"x":2.5},"3,2","3,3"],
            [{"r":-60,"rx":6,"ry":4.5,"y":-1.4,"x":-0.5,"w":2},"3,4"]
        ]
    }
}
```
After editing, make sure you save all files. Now you will need to flash the firmware_(steps are [here](https://github.com/Baxtrom/bx01/blob/main/setup.md#compiling-and-flashing-firmware))_. Now open the via app. It's normal for your board to not be recognized at first. Head over to settings and enable ```Show design tab```. The design tab will now appear, open it. Now press the ```Load``` button, and open the ```via.json``` file. Your keyboard should now show up in the configure menu, if it doesnt try unplugging it and plugging it back in after a few second. You can now use the full via software. To configure your board, plenty of ressources can be found online.

### Compiling and flashing firmware
To "install" your code onto your keyboard you will need to compile and flash it. To compile code, open QMK MSYS. Now enter  ```qmk compile -kb <keyboard_name> -km <keymap>``` _(Enter your keyboard name (specifially it's folder name under ```\qmk_firmware\keyboards\```) and the keymap name, either "default" or "via"(if you followed the via setup)_. For my board it would look like this ```qmk compile -kb bx01 -km via```. Hit enter and wait until the operation completes _(this could take a few minutes, you will know its done once the messages stop appearing and you see ```The firmware size is fine...``` in the last few lines)_. MSYS is built to be clear about any errors if it can't compile the firmware. If you encounter any issues, take the time to read the errors, it will usually indicate almost exact what the problem is. You will also be able to tell where they are. It will first show the problematic file path and name, and then the last 2 pairs of numbers rempresent the line number followed by the character number from left to right. For example you could get this code: ```/keyboard/??/keymaps/default/keymap.c:14:11```. This would mean character 11 on line 14 of the keymap.c file in the default keymap folder, has an error. Once compiling is done, a ```.hex``` file will be created in the ```/qmk_firmware``` folder. Now open QMK toolbox and press ```Open``` and load the .hex file you just compiled. Now select your MCU _(micro-controller, for example on a pro micro it will be the ATmega32U5)_. Turn ```Auto-flash```. Plug in your board. Now get your microcontroller into bootloader mode. The procedure varies by model, so look it up _(for a pro micro, bridge the GND and RST pins with something conductive twice in a row quickly)_. Now you'll see text pop up in QMK toolbox as your board is being flashed, this shouldn't take very long. When it's done you will get a message saying the flash is complete and your device was disconnected. Now your keyboard should work just as intended _(try unplugging it and replugging it if it's not recognized.)_. You can now enjoy your new custom keyboard! If you ever wish to modify anything just go through these steps again starting from [here](https://github.com/Baxtrom/bx01/blob/main/setup.md#keymapc) and if you are making a new prototype, or a different keyboard entirely start back from [here](https://github.com/Baxtrom/bx01/blob/main/setup.md#creating-your-keyboard-file)


