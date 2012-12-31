# UnitTest++ Example

This is an example of using [UnitTest++ framework](http://unittest-cpp.sourceforge.net/) to do unit testing for a game.

Note that it is not complete, and is purely an example of some passing tests.
Modify some of the code (for example, the starting position of the Physics
Object) and see what happens.

## Setup

You will have to update the include path of UnitTest++.h in `main.cpp` to point to your
installation.

Also, update the path to the libUnitTest++ library file in `Makefile`

## Compiling and running

    $ cd /path/to/src
    $ make clean && make all
    $ ./tests
