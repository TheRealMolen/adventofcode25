#!/bin/sh

mkdir -p build/dbg
mkdir -p build/rel
mkdir -p build/opt

mkdir -p bin

cd build/dbg
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ../..
cd ../..

cd build/opt
cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo ../..
cd ../..

cd build/rel
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ../..
cd ../..


YCMCONFIG=compile_commands.json
if [ ! -e $YCMCONFIG ]; then
    ln -s build/dbg/$YCMCONFIG .
fi

