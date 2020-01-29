uunet
===============

A repository for the analysis and mining of networks maintained by the Uppsala University Information Laboratory.

This repository contains:

* a C++ library providing the native implementation of most of the data storage and analysis functions
developed at our lab.
* the multinet R library, making the C++ functions about multilayer network analysis available as an R package.
This is based on the book: Multilayer Social Networks, by Dickison, Magnani & Rossi, Cambridge University
Press (2016), and the latest stable version is also available on CRAN.

Documentation
-------------

* A doxygen generated *API reference* which lists all types and functions of the C++ library.
* [Unit Tests](test/) which contain small code snippets used to test each library feature.

Requirements
------------

The R version of the library only requires a recent installation of R.

The C++ version of the library requires:

* A modern, C++14-ready compiler.
* The *cmake* build system.


Installation - R
------------
The stable version of the multinet R library can be installed directly from R by typing:

```sh
install.packages("multinet")
```

Installation - C++
------------

To download and install the library use the following commands.

```sh
git clone https://magnanim@bitbucket.org/uuinfolab/net.git
cd net
cd C++

mkdir build
cd build

cmake ..
make
```

This compiles and generates a shared library into the `build` directory.
A different location can be specified by executing cmake from another folder.

The documentation is generated inside the `build/doc` directory, while the
testing suite will reside in `build/test`. In order run the test suite execute:

```sh
./net-tests
```

To install the library in your system use the generated Makefile script:

```sh
make install
```

