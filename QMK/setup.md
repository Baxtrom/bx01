## Qmk setup
_please note that this page is mostly for my personal reference when setting up qmk for a custom build again, but if it can be of any help feel free to refer to it_

### Software needed
- Code editor _(i reccomend VScode)_
- QMK MSYS _(https://msys.qmk.fm)_
- QMK toolbox _(https://github.com/qmk/qmk_toolbox/releases)_

### Ressources 
- QMK docs _(https://docs.qmk.fm/#/)_
- QMK file docs _( ```qmk_firmware/docs``` either on the qmk github page or on your local install)_
- Youtube (people such as joe scotto, jan lunge, datulab tech, djambo)

### First setup
Open QMK MSYS and run ```qmk setup ```. Answer y to all questions. 
Once that's done, run ```qmk new-keyboard```. Answer all questions with required info _(name, github username, real name)_. Then when asked to pick a base layout enter ```51``` _(none of the above)_  if you want to start from scratch _(which i'd reccomend to get comfortable with qmk)_. When asked for your microcontroller (MCU), enter the appropriate number _(it's important to get this right)_. I used a pro micro, which has an atmega32u4. Now your setup is good.

### Editing the files
Naviguate to the qmk firmware folder (should be in your user folder) ```C:\Users\<user>\qmk_firmware\keyboards```. Find and open the folder with the same name as your keyboard. Once open, go to the navigation bar up top and delete the file path and replace it with just ```cmd``` and hit enter. This will open the console. Now type ```code .```. This will open the folder in VScode where you can start editing files. ![CMD](https://github.com/Baxtrom/bx01/assets/152244482/36e02226-12c5-4411-b9b0-8c1d5301707b)  

#### Config.h, readme.md, rules.mk
These are used to enable certain features and provide documentation to others using your files, you won't really need to change these, but more info can be found in the qmk docs. 
