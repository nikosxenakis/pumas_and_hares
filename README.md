[![MIT license](http://img.shields.io/badge/license-MIT-brightgreen.svg)](http://opensource.org/licenses/MIT) 
[![Build                status](https://travis-ci.com/nikosxenakis/pumas_and_hares.svg?token=5FvzyxcLtApTEz5x7oVA&branch=master)](https://travis-ci.org/nikosxenakis)

# Pumas and Hares
This repository is the outcome of a group project for the Programming Skills class in the 2018 High Performance Computing Masters at Edinburgh University. The program held is this repository is  a two-dimensional predator-prey model with spatial diffusion using C++. The aim was to produce a “best 
practice” scientific code within a full development framework (i.e. revision control, build tools, unit test, framework etc.). 

### Prerequisites
```
Compiler: g++
Debug: gdb
Build tool: make
Test tool: Catch2
```

### Installing

To install this repository, simply use the commands below

```
make clean
make all
make run ./resources/islands.dat
```

## Building

* [GNU Make](https://www.gnu.org/software/make/) 

All build files are placed in the build directory

## Input files

The landscape for the model is supplied as a ASCII file which describe which tiles are land or water. Sample input files can be found in the `/resources` directory.
You can select which file to use as input at run time by supplying it as a command line arguement i.e. `./bin/pumas_and_hares ./resources/small3x3.dat`
The format of the file is:

```
3 3
1 1 1
1 1 1
1 1 1
```

Where the first line gives the size of the landscape in x, y and the landscape is described as either 0 or 1 for water or land respectively.
Alternatively the density of Pumas and Hares at each grid point can be specified with the format:

```
3 3
1,0,0 1,0,0 1,0,0
1,0,0 1,1,1 1,0,0
1,0,0 1,0,0 1,0,0
```

Where the density of pumas are hares follows the landscape descriptor.


### Parameters

The parameters which the program uses at run time are defined in the resources/param.json file.

Key:
  *  `r`: birth rate of the hares
  *  `a`: predation rate at which pumas eat hares
  *  `b`: birth rate of pumas per one hare eaten
  *  `m`: puma mortality rate
  *  `k`: diffusion rate for hares
  *  `l`: diffusion rate for pumas
  *  `t`: time step
  *  `T`: interval at which a ppm file is generated.

## Output

At each T the average puma and hare density over all land tiles is written in `/output/average_density.txt`

The code outputs a ppm file at each T showing the density of pumas across the landscape to the `/output` directory. The colour code in the file is as follows:

  * Red: Pumas
  * Green: Hares
  * Blue: Water
  * White: Land (no hares or pumas)

For Pumas and Hares the intensity of the colour is proportional to the density, with the brightest colour corresponding to the maximum density.

For landscapes with a dimension smaller than 100 each 10 x 10 pixel square represents a single land square from the input.

For landscapes with a dimension larger than 100 the output is averaged so that 10 x 10 pixel a square represents the average of multiple input land squares. This is to reduce the file size of the ppm file. Information about the number of input squares per output square is printed to the screen at run time.

## Design Decisions

We group functionalities into logic classes. Most of these classes are deployed following a `singleton pattern` or `static pattern`.
For instance `Hare` and `Model` classes carry `birth_rate`, `predation_rate`, `mortality_rate` and `diffusion_rate`.
These parameters and the calculation formula for density are the same across the whole landscape and do not change after initalisation.
Thus, we implemented both classes as static and never create a single object of them.

Puma and Hare densities and the boolean whether a tile is considered land or water are specific to individual tiles.
Following a strict object-orientation paradigm we create an object for every `tile` of the landscape.
Slicing the landscape for output we also initialise one `tileData` object per slice.

* UML diagrams
* see more diagrams in index.html

explain dependency decoupling (configData, Helpers, Parser)

## Platforms

The simulations run on both DICE and Cirrus supercomputers

## Third Party Tools

* [Catch](https://catch-lib.net) for the test library
* [JSON](https://github.com/nlohmann/json) for the json parser library
* [DoxyGen](https://github.com/doxygen/doxygen) for generating documentation from annotated C++ sources

## Running the tests

To build and run these tests, simply use the command `make test`. Once the tests have finished compiling, you can run them using `./bin/test/`

### Test style and reasoning

We wrote our tests according to a behaviour driven development style. Whilst tests were not always written before their corresponding classes, we found this style of testing to be expressive and self-documenting. Tests follow the naming convention test\_$shadowed\_class.cpp

### Coding style

```
class MyClass {
	int myFunc(int myVar) {
	    return myVar;
	}
}
```

### Documentation

C++ header files contain in line documentation

## Versioning

We use [GitHub](http://github.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/nikosxenakis/pumas_and_hares). 

## Authors

* **Xenakis Nikolaos** - *Initial work-Modelling* - [nikosxenakis](https://github.com/nikosxenakis)
* **Jim Walker** - *Building tests, CI*
* **Holly Judge** - *I/O interface*
* **Mark Klaisoongnoen** - *Modelling*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgements

* Hat tip to anyone whose code was used
