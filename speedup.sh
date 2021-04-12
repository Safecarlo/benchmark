#!/bin/bash

index=1
serial_file=$1
vector_file=$2
output_file=$3

rm -Rf $output_file

for i in 2, 4, 8 ; do
    index=$(($index + 1))
    serial=$(cat $serial_file | sed -n $index"p" | cut -d";" -f2)
    vector=$(cat $vector_file | sed -n $index"p" | cut -d";" -f2)
    ./compute $i $vector $serial 2>> $output_file
done

