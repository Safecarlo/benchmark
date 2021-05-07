#!/bin/bash

# Check argument
if [ $# != 1 ] ; then
    echo "Usage: ./run.sh [CORE ID]"
    exit 0
fi

# Recup the core
core=$1

# Check if core is available
if ! taskset -c $core echo "hello" 2> /dev/null ; then
    echo "Sorry, $core is not available"
    exit 0
fi

# clean
make clean

# compile
make

# change verificarlo option
export VFC_BACKENDS_SILENT_LOAD="True"
export VFC_BACKENDS_LOGGER="False"

# ieee
VFC_BACKENDS="libinterflop_ieee.so" taskset -c $core ./main 2.0 1.0 2> ieee.txt
echo "ieee benchmark completed"

# vprec normal
VFC_BACKENDS="libinterflop_vprec.so" taskset -c $core ./main 2.0 1.0 2> vprec_normal.txt
echo "vprec normal benchmark completed"

# vprec denormal
VFC_BACKENDS="libinterflop_vprec.so" taskset -c $core ./main 0x2.0p-130 0x1.0p-130 2> vprec_denormal.txt
echo "vprec denormal benchmark completed"

# reset verificarlo option
export VFC_BACKENDS_SILENT_LOAD="False"
export VFC_BACKENDS_LOGGER="True"
