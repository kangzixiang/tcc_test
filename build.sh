#!/bin/bash

CURRENT_DIR=$(cd $(dirname $0); pwd)
FILE=${CURRENT_DIR}/products

tinycc_dir=${CURRENT_DIR}/tinycc

if [ ! -d "$FILE" ]; then
    echo "$FILE not exist"
    mkdir ${FILE}
fi

# Build tinycc
cd ${tinycc_dir} && ./configure --prefix=$HOME/tcc-host && make -j8 && make install
# Build tcc_test
cd ${FILE} && cmake .. && make -j8