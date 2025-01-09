#! /bin/bash
# add executable permission for this file by running: chmod +x ./compile.sh

# Define variables
ROOT_DIR=$(pwd)
BUILD_DIRECTORY=$ROOT_DIR/out/build
EXECUTIBLE=$BUILD_DIRECTORY/out

# Cmake commands
cmake -S $ROOT_DIR -B $BUILD_DIRECTORY
cd $BUILD_DIRECTORY && make && cd $ROOT_DIR