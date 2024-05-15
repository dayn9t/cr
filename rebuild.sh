mkdir ../cr-build
cd ../cr-build
rm * -rf
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ../cr
ninja
ls -lah bin lib
