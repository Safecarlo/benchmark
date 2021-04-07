set term png size 1900,1000 noenhanced font "Terminal,10"

set datafile separator ";"

set grid

set auto x

set key right top

set title "CPU_NAME bandwidth (in Gib/s) for a simple addition benchmark of 2 arrays to another array"

set xlabel "Vector size variants"
set ylabel "Bandwidth in Bytes Per Second (higher is better)"

set style data histogram
set style fill solid border -1
set boxwidth 0.9

set xtic rotate by -45 scale 0

#set multiplot layout 2, 2 rowsfirst

set yrange[0:2500]

set title "Vector implementation"
plot "ieee_perf" u 2:xtic(1) t "IEEE Backend", "vprec_perf" u 2:xtic(1) t "VPREC Backend"

unset multiplot
