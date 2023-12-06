## Qmk setup
_please note that this page is mostly for my personal reference when setting up qmk for a custom build again, but if it can be of any help feel free to refer to it_

### Software needed
- Code editor _(i reccomend VScode)_
- QMK MSYS _(https://msys.qmk.fm)_
- QMK toolbox _(https://github.com/qmk/qmk_toolbox/releases)_

### First setup
Open QMK MSYS and run ```qmk setup ```. Answer y to all questions. 
Once that's done, run ```qmk new-keyboard```. Answer all questions with required info _(name, github username, real name)_. Then when asked to pick a base layout enter ```51``` _(none of the above)_
