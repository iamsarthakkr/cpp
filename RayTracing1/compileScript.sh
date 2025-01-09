#! /bin/bash
ROOT_DIR=$(pwd)

echo $ROOT_DIR

cmake -DCMAKE_CXX_FLAGS="-O3" -S . -B out/build
cd out/build && make
cd $ROOT_DIR