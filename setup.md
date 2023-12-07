## Qmk setup
_please note that this page is mostly for my personal reference when setting up qmk for a custom build again, but if it can be of any help feel free to refer to it_

### Software needed
- Code editor _(i reccomend VScode)_
- QMK MSYS _(https://msys.qmk.fm)_
- QMK toolbox _(https://github.com/qmk/qmk_toolbox/releases)_

### Ressources 
- QMK docs _(https://docs.qmk.fm/#/)_
- QMK file docs _( ```qmk_firmware/docs``` either on the qmk github page or on your local install)_
- Youtube _(people such as joe scotto, jan lunge, datulab tech, djambo)_

### First setup
Open QMK MSYS and run ```qmk setup ```. Answer y to all questions. 
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
Next, choose which key you want to use to switch layers. You need to replace it's keycode with ```MO(<layer number>)``` _(like shown in the bottom right key  in the code above)_. This key will now switch to the layer indicated, while you hold the key. There are a few keycodes for changing layers _(to toggle a layer, etc...)_. You can explore the options on the [keycode page](https://github.com/qmk/qmk_firmware/blob/834fb0b1fe47d20aac27eda39f165b96fe4ddaa6/docs/keycodes.md). Once you have decided on a key, you will need to replace the keycode of the matching key _(in the indicated layer)_ with ```KC_TRNS```, which will make it transparent, so that the layer switch key is still registered by the keyboard. You can also use this key to avoid retyping keys that are persistent throughout your layers, as keypresses will register as the next lowest layer that doesn't have ```KC_TRNS```. 