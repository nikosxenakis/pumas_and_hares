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

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
make all
make test
```

## Building

* [GNU Make](https://www.gnu.org/software/make/) - The web framework used

## Input files

The landscape for the model is supplied as a ASCII file which descibe which tiles are land or water.
The format of the file is:

3 3
1 1 1
1 1 1
1 1 1

Where the first line gives the size of the landscape in x, y and the landscape is described as either 0 or 1 for water or land respectively.
Alternatively the density of Pumas and Hares at each grid point can also be specified with the format:

3 3
1,0,0 1,0,0 1,0,0
1,0,0 1,1,1 1,0,0
1,0,0 1,0,0 1,0,0

Where the density of pumas are hares follows the landscape descriptor.

Sample input files can be found in /resources

## Json file input

## Output

The code outputs a ppm file at each T showing the density of pumas across the landscape. The colour code is as follows:

Red: Pumas
Green: Hares
Blue: Water
White: Land (no hares or pumas)

For Pumas and Hares the intensity of the colour is proportional to the density, with the brightest color corresponding to the maxium density.

## Platforms

The simulations run on both DICE and Cirrus supercomputers

## Third Party Tools

* [Catch](https://catch-lib.net) for the test library
* [JSON](https://catch-lib.net) for the json parser library

## Running the tests

To build and run these tests, simply use the command `make test`. Once the tests have finished compiling, you can run them using `./bin/test/`

### Test style and reasoning

We wrote our tests according to a behavior driven development style. Whilst tests were not always written before their corresponding classes, we found this style of testing to be expressive and self-documenting

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

* **Xenakis Nikolaos** - *Initial work-Modeling* - [nikosxenakis](https://github.com/nikosxenakis)
* **Jim Walker** - *Building tests*
* **Holly Judge** - *I/O interface*
* **Mark Klaisoongnoen** - *Modeling*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration from the lifecycle of computer games
