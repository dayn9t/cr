#!/usr/bin/env bash
build_type=Release

dst=cr-build-$build_type
mkdir ../$dst
cd ../$dst
rm * -rf
cmake -G Ninja -DCMAKE_BUILD_TYPE=$build_type ../cr
ninja
ls --color=tty -lah bin lib
