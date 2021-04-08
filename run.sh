#!/bin/bash

# clean
make clean

# compile
make

# change verificarlo option
export VFC_BACKENDS_SILENT_LOAD="True"
export VFC_BACKENDS_LOGGER="False"

# normal
## ieee
VFC_BACKENDS="libinterflop_ieee.so" taskset -c 3 ./main "n" 2> ieee_perf_normal

## vprec
VFC_BACKENDS="libinterflop_vprec.so" taskset -c 3 ./main "n" 2> vprec_perf_normal

# denormal
## ieee
VFC_BACKENDS="libinterflop_ieee.so" taskset -c 3 ./main "d" 2> ieee_perf_denormal

## vprec
VFC_BACKENDS="libinterflop_vprec.so" taskset -c 3 ./main "d" 2> vprec_perf_denormal

# reset verificarlo option
export VFC_BACKENDS_SILENT_LOAD="False"
export VFC_BACKENDS_LOGGER="True"
