set term png size 1900,1000 noenhanced font "Terminal,10"

set datafile separator ";"

set grid

set auto x

set key right top

#set title "Bandwidth (in Gib/s) for a simple addition benchmark of 2 arrays to another array"

set xlabel "Vector size variants"
set ylabel "Bandwidth in Bytes Per Second (higher is better)"

set style data histogram
set style fill solid border -1
set boxwidth 0.9

set xtic rotate by -45 scale 0

set output "ieee.png"
set multiplot layout 2, 2 rowsfirst

set yrange[0:]

set title "IEEE Backend"
plot "serial_ieee_perf.txt" u 2:xtic(1) t "Serial implementation", "vector_ieee_perf.txt" u 2:xtic(1) t "Vector implementation"
plot "serial_ieee_speedup.txt" u 2:xtic(1) t "Serial implementation", "vector_ieee_speedup.txt" u 2:xtic(1) t "Vector implementation"

unset multiplot

set output "vprec_default.png"
set multiplot layout 2, 2 rowsfirst

set yrange[0:]

set title "VPREC Backend with normal number and default setting"
plot "serial_vprec_normal_perf.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_normal_perf.txt" u 2:xtic(1) t "Vector implementation"
plot "serial_vprec_normal_speedup.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_normal_speedup.txt" u 2:xtic(1) t "Vector implementation"

set title "VPREC Backend with denormal number and default setting"
plot "serial_vprec_denormal_perf.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_denormal_perf.txt" u 2:xtic(1) t "Vector implementation"
plot "serial_vprec_denormal_speedup.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_denormal_speedup.txt" u 2:xtic(1) t "Vector implementation"

unset multiplot

set output "vprec_full.png"
set multiplot layout 2, 2 rowsfirst

set yrange[0:]

set title "VPREC Backend with normal number and full mode"
plot "serial_vprec_normal_perf.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_normal_perf.txt" u 2:xtic(1) t "Vector implementation"
plot "serial_vprec_normal_speedup.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_normal_speedup.txt" u 2:xtic(1) t "Vector implementation"

set title "VPREC Backend with denormal number and full mode"
plot "serial_vprec_denormal_perf.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_denormal_perf.txt" u 2:xtic(1) t "Vector implementation"
plot "serial_vprec_denormal_speedup.txt" u 2:xtic(1) t "Serial implementation", "vector_vprec_denormal_speedup.txt" u 2:xtic(1) t "Vector implementation"

unset multiplot
