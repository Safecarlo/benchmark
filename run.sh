#!/bin/bash

# clean
make clean

# compile
make

# change verificarlo option
export VFC_BACKENDS_SILENT_LOAD="True"
export VFC_BACKENDS_LOGGER="False"

# ieee
VFC_BACKENDS="libinterflop_ieee.so" taskset -c 3 ./main 2> ieee_perf

# vprec
VFC_BACKENDS="libinterflop_vprec.so" taskset -c 3 ./main 2> vprec_perf

# reset verificarlo option
export VFC_BACKENDS_SILENT_LOAD="False"
export VFC_BACKENDS_LOGGER="True"
