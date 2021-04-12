#!/bin/bash

serial=$(ls serial*perf.txt)
vector=$(ls vector*perf.txt)

for s in $serial ; do
    for v in $vector ; do

        s_without_prefix=${s#serial_}
        s_without_prefix_and_suffix=${s_without_prefix%_perf.txt}

        v_without_prefix=${v#vector_}
        v_without_prefix_and_suffix=${v_without_prefix%_perf.txt}

        if [ $s_without_prefix_and_suffix == $v_without_prefix_and_suffix ] ; then
            ./speedup.sh $s $v $s_without_prefix_and_suffix"_speedup.txt"
        fi
    done
done

