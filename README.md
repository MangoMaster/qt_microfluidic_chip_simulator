# qt_microfluidic_chip_simulator

qt individual project: microfluidic chip simulator.  
It can calculate the speed of output fluid on a given chip.  
This software is designed by JiaDong Wei. Calculation program is from Copyright (c) 2018 Regents of the Tsinghua University, Hailong Yao, and Weiqing Ji.

## Install & Run

First install Qt and all the other neccessary build tools.  
Under this directory, perform:
```sh
qmake
make
```  
to install this microfluidic chip simulator.  
Perform:
```sh
./microfluidic_chip_simulator
```
to run this simulator.

## Use

You can get the help below in the menu "Help".  
* New (Ctrl+N) a chip to set rows/columns & inputs/outputs.
* Click a cube to let it enabled/disabled.
* Right click a cube to set its length.
* Rubber band drag cubes to let them enabled/disabled & set their length.
* Random cubes enabled/disabled with a percentage.
* Run (Ctrl+R) and get results at the bottom.
* Drag the slider on the right to set chip's scale.
* Exit (Ctrl+Q).

## License

MIT License.