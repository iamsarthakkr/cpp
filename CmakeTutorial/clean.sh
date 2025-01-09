#! /bin/bash

# add executable permission for this file by running: chmod +x ./clean.sh

# Define variables
ROOT_DIR=$(pwd)
BUILD_DIRECTORY=$ROOT_DIR/out/build
rm -rf $BUILD_DIRECTORY/*