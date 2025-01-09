#! /bin/bash

ROOT_DIR=$(pwd)

./clean.sh
./compileScript.sh

cd $ROOT_DIR/out/build


filename=$1

if [ -z "$filename" ]
then
   filename="image"
fi

echo $filename
./out > ../res/$filename.ppm
open ../res/$filename.ppm

cd $ROOT_DIR