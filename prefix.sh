#!/bin/bash

prefix=$1

files="ieee.txt vprec_normal.txt vprec_denormal.txt"

for file in $files ; do
    mv $file $prefix"_"$file
done
