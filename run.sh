#!/bin/bash

# clean
make clean

# compile
make

# change verificarlo option
export VFC_BACKENDS_SILENT_LOAD="True"
export VFC_BACKENDS_LOGGER="False"

# ieee
VFC_BACKENDS="libinterflop_ieee.so" taskset -c 3 ./main 1.0 1.0 2> ieee_tmp.txt
cat ieee_tmp.txt | sed -n "1,4p" > ieee_perf.txt
cat ieee_tmp.txt | sed -n "5,7p" > ieee_speedup.txt

# vprec normal
VFC_BACKENDS="libinterflop_vprec.so" taskset -c 3 ./main 1.0 1.0 2> vprec_normal_tmp.txt
cat vprec_normal_tmp.txt | sed -n "1,4p" > vprec_normal_perf.txt
cat vprec_normal_tmp.txt | sed -n "5,7p" > vprec_normal_speedup.txt

# vprec denormal
VFC_BACKENDS="libinterflop_vprec.so" taskset -c 3 ./main 0x1.0p-130 0x1.0p-130 2> vprec_denormal_tmp.txt
cat vprec_denormal_tmp.txt | sed -n "1,4p" > vprec_denormal_perf.txt
cat vprec_denormal_tmp.txt | sed -n "5,7p" > vprec_denormal_speedup.txt

# vprec full normal
VFC_BACKENDS="libinterflop_vprec.so --mode=full" taskset -c 3 ./main 1.0 1.0 2> vprec_full_normal_tmp.txt
cat vprec_full_normal_tmp.txt | sed -n "1,4p" > vprec_full_normal_perf.txt
cat vprec_full_normal_tmp.txt | sed -n "5,7p" > vprec_full_normal_speedup.txt

# vprec full denormal
VFC_BACKENDS="libinterflop_vprec.so --mode=full" taskset -c 3 ./main 0x1.0p-130 0x1.0p-130 2> vprec_full_denormal_tmp.txt
cat vprec_full_denormal_tmp.txt | sed -n "1,4p" > vprec_full_denormal_perf.txt
cat vprec_full_denormal_tmp.txt | sed -n "5,7p" > vprec_full_denormal_speedup.txt

# reset verificarlo option
export VFC_BACKENDS_SILENT_LOAD="False"
export VFC_BACKENDS_LOGGER="True"
