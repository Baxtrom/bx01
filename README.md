# bx01
My first attempt at building a hand-wired, custom, 3d printed gaming keyboard/macro pad with hotswap 

![Fully_Assembled2](https://github.com/Baxtrom/bx01/assets/152244482/e0b6d013-c037-442b-86c9-37bb19da8384)

The layout, case and plate have all been designed by me. The keyboard runs on an Arduino Pro Micro running custom QMK firmware and has VIA support. The current layout has 4 layers, 3 of which are mostly empty, but I plan on adding more later. There is no lighting but it can easily be added. The wiring is all done without solder. 

The case has risers for the pro micro and it clicks/locks in place pretty solidly. The plate is 1.5 mm thick (mx switch spec) which allows the switches and the stabilizers to click in. The plate and case attach together with screws to minimize any flex. They were both designed in blender and printed on an Ender 3 in pla at 0.2mm layer height and have pretty good tolerances. I also quickly made some cable combs for easier cable management (see /photos folder). The only part I didn't design is the hot-swap sockets, which were made by Jan Lunge (https://github.com/JanLunge/keyboards/blob/main/hotswap_socket/hotswap_mx__compact.stl) and work great in this project. 

The code is setup to use pins 15, A0, A1, A2, A3 for the collums and pins D7, E6, B4, B5 for rows (see /Layout+Wiring folder for wiring schematic). I reffered to guides by jan lunge and jo scotto on youtube for the wiring. Figuring out QMK from scratch was quite a struggle but youtube was







# Materials:
- PBT keycaps 
- Akko CS crystal blue (budget linear switches)
- Knockoff arduino pro micro
- Durock stabilizer (2u, for the space key)
- 1N4148 diodes (installed in collumn2row direction)
- 24 gauge cable (tinned copper + solid core) 
- 205 g0. Used to lube stabilizer and switches
- Small elastics (brace elastics work well). Used to reduce switch wobble in the plate. Wrap them under the lip of the switch before you click them in
