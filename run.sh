#!/bin/bash

FILES="$(find ./src -type f -name '*.cpp') $(find ./cmd -type f -name '*.cpp')"

g++ $FILES \
-o game \
-Isrc \
-Iinclude \
-Ilib/include \
-lraylib

if [ $? -ne 0 ]; then
    echo "compile error"
    exit 1
fi

./game