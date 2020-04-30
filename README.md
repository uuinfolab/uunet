# uunet

This repository contains C++ code for the analysis and mining of networks produced by the
Uppsala University Information Laboratory (https://infolab.it.uu.se). _uunet_ provides most
of the code behind the R and Python _multinet_ libraries.

## Requirements

To install, use and modify the library you need:

* A recent version of git.
* The *cmake* build system.
* A modern, C++14-ready compiler.
* Doxygen (optional, only to generate the API reference documentation)

## Installation

To download the library:

```sh
git clone --recurse-submodules https://bitbucket.org/uuinfolab/uunet.git
cd uunet
```

Then create a build directory and cd into it (all the following instructions will be executed inside this directory):

```sh
mkdir build
cd build
```

To install the library:

```sh
cmake ..
make
make install
```

To compile the tests, run cmake with the option `-DCMAKE_BUILD_TYPE=Debug`. Make will then also generate
an executable running all the unit tests:

```
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
./run_tests
```

To produce the API reference documentation, use the option `-DDOXY=On`:

```
cmake .. -DDOXY=On
make doc
```

The documentation is generated inside the `build/doc` directory.

## Documentation

* All classes, functions, etc. are documented inside the .hpp files.
* This documentation can be compiled into an API reference listing all types and functions using Doxygen, as described above.
* [Short examples](examples/) are provided to illustrate the functionality of the library.
* [Unit Tests](test/) also provide small code snippets used to test most of the features of the library.

## Contribute

TBD

## Contact

For any inquiries regarding this repository you can contact <matteo.magnani@it.uu.se>.


