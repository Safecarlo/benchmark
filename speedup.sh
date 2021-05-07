#!/bin/bash

speedup_backend()
{
    index=1
    serial_file=$1
    vector_file=$2
    output_file=$3

    rm -Rf $output_file

    for op in add sub mul div ; do
        echo $op"_float; 1.0" >> $output_file
        for i in 2 4 8 ; do
            index=$(($index + 1))
            serial=$(cat $serial_file | sed -n $index"p" | cut -d";" -f2)
            vector=$(cat $vector_file | sed -n $index"p" | cut -d";" -f2)
            ./compute $op $i $vector $serial 2>> $output_file
        done
        index=$(($index + 1))
    done
}

files=$(ls serial*)

for f in $files ; do
    f_without_prefix=${f#serial_}
    f_without_prefix_and_suffix=${f_without_prefix%.txt}

    speedup_backend "serial_"$f_without_prefix_and_suffix".txt" "vector_"$f_without_prefix_and_suffix".txt" $f_without_prefix_and_suffix"_speedup.txt"
done

speedup_backend "normal_serial_vprec_normal.txt" "vector_vprec_normal.txt" "serial_vprec_normal_speedup.txt"
