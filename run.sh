#!/bin/bash

# clean
make clean

# compile
make

# change verificarlo option
export VFC_BACKENDS_SILENT_LOAD="True"
export VFC_BACKENDS_LOGGER="False"

# ieee
echo "ieee performance:"
VFC_BACKENDS="libinterflop_ieee.so" taskset -c 3 ./main

# vprec
echo "vprec performance:"
VFC_BACKENDS="libinterflop_vprec.so" taskset -c 3 ./main 

# reset verificarlo option
export VFC_BACKENDS_SILENT_LOAD="False"
export VFC_BACKENDS_LOGGER="True"
