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

set multiplot layout 2, 2 rowsfirst

set yrange[0:14000]

set title "Scalar implementation"
plot "scalar_ieee_perf" u 2:xtic(1) t "IEEE Backend", "scalar_vprec_perf" u 2:xtic(1) t "VPREC Backend"

set title "Vector implementation"
plot "vector_ieee_perf" u 2:xtic(1) t "IEEE Backend", "vector_vprec_perf" u 2:xtic(1) t "VPREC Backend"

set title "IEEE Backend"
plot "scalar_ieee_perf" u 2:xtic(1) t "Scalar implementation", "vector_ieee_perf" u 2:xtic(1) t "Vector implementation"

set title "VPREC Backend"
plot "scalar_vprec_perf" u 2:xtic(1) t "Scalar implementation", "vector_vprec_perf" u 2:xtic(1) t "Vector implementation"

unset multiplot
