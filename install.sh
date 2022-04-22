#!/bin/sh -e

mkdir -p build && cd build
cmake ../ 
cmake --build .
cmake --install .
mv MemoryEditor ..
