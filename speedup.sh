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
    done
}

serial=$(ls serial*.txt)
vector=$(ls vector*.txt)

for s in $serial ; do
    for v in $vector ; do

        s_without_prefix=${s#serial_}
        s_without_prefix_and_suffix=${s_without_prefix%.txt}

        v_without_prefix=${v#vector_}
        v_without_prefix_and_suffix=${v_without_prefix%.txt}

        if [ $s_without_prefix_and_suffix == $v_without_prefix_and_suffix ] ; then
            speedup_backend $s $v $s_without_prefix_and_suffix"_speedup.txt"
        fi
    done
done

