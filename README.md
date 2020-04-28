# uunet

This repository contains code produced by the Uppsala University Information Laboratory (https://infolab.it.uu.se) for the analysis and mining of networks.

## Requirements

To install, use and develop the library you need:

* A recent version of git.
* A modern, C++14-ready compiler.
* The *cmake* build system.

If you want to generate the API reference documentation you also need:

* Doxygen

## Installation

To download and install the library use the following commands.

```sh
git clone https://bitbucket.org/uuinfolab/uunet.git
cd uunet

mkdir build
cd build

cmake ..
make
```

This compiles and generates a shared library into the `build` directory.
A different location can be specified by executing cmake from another folder.

The documentation is generated inside the `build/doc` directory, while the
testing suite will reside in `build/test`. In order to run the test suite execute:

```sh
./core-tests
./net-tests
```

To install the library in your system use the generated Makefile script:

```sh
make install
```
## Documentation

* A doxygen generated *API reference* which lists all types and functions of the C++ library.
* [Unit Tests](test/) which contain small code snippets used to test each library feature.

## Contribute

TBD

## Contact

For any inquiries regarding this repository you can contact <matteo.magnani@it.uu.se>.


