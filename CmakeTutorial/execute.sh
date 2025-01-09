#! /bin/bash
# add executable permission for this file by running: chmod +x ./execute.sh

# Define variables
ROOT_DIR=$(pwd)
BUILD_DIRECTORY=$ROOT_DIR/out/build
EXECUTIBLE=$BUILD_DIRECTORY/out

# compile
./compile.sh

cd $BUILD_DIRECTORY
./out
 cd $ROOT_DIR

