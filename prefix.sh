#!/bin/bash

prefix=$1

files=$(ls ieee*perf.txt vprec*perf.txt ieee*speedup.txt vprec*speedup.txt)

for file in $files ; do
    mv $file $prefix"_"$file
done
