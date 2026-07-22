#!/bin/bash

FILES="$(find ./src -type f -name '*.cpp') $(find ./cmd -type f -name '*.cpp')"

g++ $FILES \
-g \
-O0 \
-o game \
-Isrc \
-Iinclude \
-Ilib/include \
-lraylib \
-lcurl \
-lpqxx \
-lpq

if [ $? -ne 0 ]; then
    echo "compile error"
    exit 1
fi

gdb \
-batch \
-ex "run" \
-ex "bt full" \
--args ./game