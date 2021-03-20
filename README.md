# The uunet library

This repository contains C++ code for the analysis and mining of networks produced by the
Uppsala University Information Laboratory (InfoLab, https://infolab.it.uu.se). _uunet_ provides most
of the code behind the R and Python _multinet_ libraries.

## Requirements

To install, use and modify the library you need:

* A recent version of git.
* The *cmake* build system version 3.15 or higher.
* A C++14 compiler.
* Doxygen (optional, only to generate the API reference documentation).

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

## Tests

To compile the tests, run cmake with the option `-DCMAKE_BUILD_TYPE=Debug`. Make will then also generate
an executable running all the unit tests:

```
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
./run_tests
```


## Documentation

An overview of the library is available under `docs/` as a pdf file. Its latex source is also available.

All classes, functions, etc. are documented inside the .hpp files. This documentation can be compiled into an API reference listing all types and functions using Doxygen. To produce the API reference documentation, use the option `-DDOXY=On`:

```
cmake .. -DDOXY=On
make doc
```

The documentation is generated inside the `build/doc` directory.

[Short examples](examples/) are also provided to illustrate the functionality of the library. Individual examples
correspond to the .cxx files inside the `examples/` directory, and can be individually compiled and executed using
the name of the example (from inside the `build/` directory):

```
make creation
./creation
```

One can also compile all the examples in one line:
```
make examples
# now all the individual examples can be executed
./creation
./networks
# ...
```

[Unit Tests](test/) also provide small code snippets used to test most of the features of the library, so they can
also be used as documentation.


## Contribute

The `master` branch contains more stable code, mainly updated when new versions of the R and Python
libraries are released and when new research articles using the library are submitted. The `master` branch is
updated by the administrators from the `development` branch. Please 

## Contact

For any inquiries regarding this repository you can contact <matteo.magnani@it.uu.se>.


