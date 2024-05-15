#!/usr/bin/env bash

mkdir ../cr-build
cd ../cr-build
rm * -rf
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ../cr
ninja
ls --color=tty -lah bin lib
