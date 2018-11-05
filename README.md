[![MIT license](http://img.shields.io/badge/license-MIT-brightgreen.svg)](http://opensource.org/licenses/MIT) 
[![Build                status](https://travis-ci.com/nikosxenakis/pumas_and_hares.svg?token=5FvzyxcLtApTEz5x7oVA&branch=master)](https://travis-ci.org/nikosxenakis)

# Pumas and Hares
This repository is the outcome of a group project for the Programming Skills class in the 2018 High Performance Computing Masters at Edinburgh University. The program held is this repository is  a two-dimensional predator-prey model with spatial diffusion using C++. The aim was to produce a “best 
practice” scientific code within a full development framework (i.e. revision control, build tools, unit test, framework etc.). 

## Prerequisites

* Compiler: [GNU g++](https://www.gnu.org/software/gcc/)
* Debugger: [GNU gdb](https://www.gnu.org/software/gdb/)
* Build tool: [GNU Make](https://www.gnu.org/software/make/)
* Test tool: [Catch](https://catch-lib.net)
* Documentation tool: [DoxyGen](https://github.com/doxygen/doxygen)
* JSON Pascer: [JSON](https://github.com/nlohmann/json)

## Usage

### Installation

To install this repository

```
git clone https://github.com/nikosxenakis/pumas_and_hares.git
cd pumas_and_hares
```

### Building

To build this repository including the main project, test files and land generator

```
scripts/make.sh
```

### Running

To run the project just choose one of the following commands

```
scripts/pumas_and_hares.sh //run an example of the project that is described in the script
make run //run an example of the project with the default values
make run ./resources/input_files/islands.dat //run an example of the project with specific input file
make run ./resources/input_files/islands.dat ./resources/configurations/param.json //run an example of the project with specific input and configuration file
scripts/pumas_and_hares_all.sh //run the project with all the combinations of the input and configuration files available
```

After the execution, to create the average variation of the densities over time run

```
python scripts/data_analyzer.py
```

then display average_density.eps

## Input files

The landscape for the model is supplied as a ASCII file which describe which tiles are land or water. Sample input files can be found in the `./resources/input_files` directory.
You can select which file to use as input at run time by supplying it as a command line arguement i.e. `./bin/pumas_and_hares ./resources/input_files/small3x3.dat`
The format of the file is:

```
3 3
1 1 1
1 1 1
1 1 1
```

Where the first line gives the size of the landscape in x, y and each square of the landscape is described with either 0 or 1, for water or land respectively. In this case the initial density of hares and pumas in each land square will be assigned randomly with a density between 0 and 5. 

Alternatively the initial density of pumas and hares on each land square can be specified with the format:

```
3 3
1,0,0 1,0,0 1,0,0
1,0,0 1,1,1 1,0,0
1,0,0 1,0,0 1,0,0
```

Where the density of pumas and hares follows the landscape descriptor e.g. `land, puma_density, hare_density`. If a density is assigned to a non land square then it will be ignored and the square will be set to water. If there is an error in the input file the program will terminate.


### Parameters

The parameters which the program uses at run time are defined in the `resources/configurations/param.json` file.

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

The code outputs a ppm file to the `/output` directory at each T showing the density of pumas across the landscape. These can be viewed using the `display` command:

```
display Density_000.ppm
```

The colour code in the file is as follows:

![Landscape example](https://github.com/nikosxenakis/pumas_and_hares/raw/master/docs/img/landscape_output.png)

  * `Red`: Pumas
  * `Green`: Hares
  * `Blue`: Water  * `White`: Land (no hares or pumas)

For pumas and hares the intensity of the colour is proportional to the density, with the brightest colour corresponding to the maximum density. The colour scale is shown below.

![scale example](https://github.com/nikosxenakis/pumas_and_hares/raw/master/docs/img/scale.png)


For landscapes with a dimension smaller than 100 squares each 10 x 10 pixel square represents a single land square from the input.

For landscapes with a dimension larger than 100 squares the output is averaged so that 10 x 10 pixel a square represents the average of multiple input land squares. This is to reduce the file size of the ppm file when using large landscapes. Information about the number of input squares averaged into an output square is printed to the screen at run time.

## Design Decisions

We group functionalities into logic classes. Our classes are deployed as `singleton`, `static` and following `object-orientation`.

![UML diagram of class Hare](https://github.com/nikosxenakis/pumas_and_hares/raw/master/docs/class_hare__coll__graph.png)
![UML diagram of class configData](https://github.com/nikosxenakis/pumas_and_hares/raw/master/docs/class_config_data__coll__graph.png)

For instance `Hare` and `Model` classes carry `birth_rate`, `predation_rate`, `mortality_rate` and `diffusion_rate`.
These parameters and the calculation formula for density `Hare::calculateNewDensity()` are the same across the whole
landscape and do not change after initalisation. The same explanation applies to `Helpers` and `ConfigData`.
Thus, we implemented both classes as static and never create a single object of them.

![UML diagram of class Landscape](https://github.com/nikosxenakis/pumas_and_hares/raw/master/docs/class_landscape__coll__graph.png)
![UML diagram of class Tile](https://github.com/nikosxenakis/pumas_and_hares/raw/master/docs/class_tile__coll__graph.png)

With `Landscape` we create a single object that carries all `Tile`s. `Tile` represents a single data point in the grid.
For output, we use `TileData` to group multiple `Tile`s together in grid slices. For both classes we follow `object-orientation`.
Puma and Hare densities and the boolean - whether a `Tile is considered land or water - are specific to individual tiles.

* UML diagrams
* see more diagrams in index.html

explain dependency decoupling (configData, Helpers, Parser)

## Platforms

The simulations run on both the university's DICE network and the Cirrus supercomputer cluster.

## Third Party Tools

* [Catch](https://catch-lib.net) for the test library

Catch was chosen as the test library for this project as it is a simple, header only test framework with support for behavior driven development. As it has no external dependencies, Catch was easy to install start deveoping with.

* [JSON](https://github.com/nlohmann/json) for convenient JSON-parsing our parameters from a config file
* [DoxyGen](https://github.com/doxygen/doxygen) for generating documentation from annotated C++ sources

## Testing

### Running

To run the tests

```
scripts/tests.sh
```

### Continuous Integration

* [TRAVIS-CI](https://travis-ci.com/nikosxenakis/pumas_and_hares)

### Test style and reasoning

We wrote our tests according to a behaviour driven development style. Whilst tests were not always written before their corresponding classes, we found this style of testing to be expressive and self-documenting. Tests follow the naming convention test\_$shadowed\_class.cpp

## Land Generator

To create a new landscape run

```
scripts/land_generator.sh
```

The new landscape can be found in ./resources/input_files/new_2000x2000.dat

## Coding style

```
class MyClass {
	int myFunc(int myVar) {
	    return myVar;
	}
}
```

## Documentation

C++ header files contain in line documentation
We used [DoxyGen](https://github.com/doxygen/doxygen)
To auto-generate a website-documentation run

```
scripts/documentation.sh
```
You can check by opening with your browser the docs/index.html file the project directory

## Versioning

We use [GitHub](http://github.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/nikosxenakis/pumas_and_hares). 

## Authors

* **Xenakis Nikolaos** - *Initial work-Modelling* - [nikosxenakis](https://github.com/nikosxenakis)
* **Jim Walker** - *Building tests, CI*
* **Holly Judge (Tetlow)** - *I/O interface*
* **Mark Klaisoongnoen** - *Modelling*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgements

* Thanks to anyone whose code was used
