#!/bin/bash

if [ ! -d build ]; then
    mkdir build && cd build
    cmake ..
    cmake --build .
fi
./main