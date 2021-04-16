set term png size 1900,1000 noenhanced font "Terminal,10"

set datafile separator ";"

set grid

set auto x

set key right top

set xlabel "Vector size variants"

set style data histogram
set style fill solid border -1
set boxwidth 0.9

set xtic rotate by -45 scale 0

# IEEE BACKEND

set output "ieee.png"
set multiplot layout 2, 2 rowsfirst

set title "IEEE Backend"

set yrange[0:]

set ylabel "Bandwidth in Giga Bits Per Second (higher is better)"
plot "serial_ieee_perf.txt" u 2:xtic(1) t "Serial implementation",             \
     "vector_ieee_perf.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:5]

set ylabel "Speedup in Pourcentage (higher is better)"
plot "serial_ieee_speedup.txt" u 2:xtic(1) t "Serial implementation",          \
     "vector_ieee_speedup.txt" u 2:xtic(1) t "Vector implementation",          \
     "ieee_speedup.txt" u 2:xtic(1) t "Vector / Serial"

unset multiplot

# VPREC DEFAULT

set output "vprec_default.png"
set multiplot layout 2, 2 rowsfirst

set title "VPREC Backend with normal number and default setting"

set yrange[0:16000]

set ylabel "Bandwidth in Giga Bits Per Second (higher is better)"
plot "serial_vprec_normal_perf.txt" u 2:xtic(1) t "Serial implementation",     \
     "vector_vprec_normal_perf.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:5]

set ylabel "Speedup in Pourcentage (higher is better)"
plot "serial_vprec_normal_speedup.txt" u 2:xtic(1) t "Serial implementation",  \
     "vector_vprec_normal_speedup.txt" u 2:xtic(1) t "Vector implementation",  \
     "vprec_normal_speedup.txt" u 2:xtic(1) t "Vector / Serial"

set title "VPREC Backend with denormal number and default setting"

set yrange[0:16000]

set ylabel "Bandwidth in Giga Bits Per Second (higher is better)"
plot "serial_vprec_denormal_perf.txt" u 2:xtic(1) t "Serial implementation",   \
     "vector_vprec_denormal_perf.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:5]

set ylabel "Speedup in Pourcentage (higher is better)"
plot "serial_vprec_denormal_speedup.txt" u 2:xtic(1) t "Serial implementation",\
     "vector_vprec_denormal_speedup.txt" u 2:xtic(1) t "Vector implementation",\
     "vprec_denormal_speedup.txt" u 2:xtic(1) t "Vector / Serial"

unset multiplot

# VPREC FULL

set output "vprec_full.png"
set multiplot layout 2, 2 rowsfirst

set title "VPREC Backend with normal number and full mode"

set yrange[0:16000]

set ylabel "Bandwidth in Giga Bits Per Second (higher is better)"
plot "serial_vprec_full_normal_perf.txt" u 2:xtic(1) t "Serial implementation",     \
     "vector_vprec_full_normal_perf.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:5]

set ylabel "Speedup in Pourcentage (higher is better)"
plot "serial_vprec_full_normal_speedup.txt" u 2:xtic(1) t "Serial implementation",  \
     "vector_vprec_full_normal_speedup.txt" u 2:xtic(1) t "Vector implementation",  \
     "vprec_full_normal_speedup.txt" u 2:xtic(1) t "Vector / Serial"

set title "VPREC Backend with denormal number and full mode"

set yrange[0:16000]

set ylabel "Bandwidth in Giga Bits Per Second (higher is better)"
plot "serial_vprec_full_denormal_perf.txt" u 2:xtic(1) t "Serial implementation",   \
     "vector_vprec_full_denormal_perf.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:5]

set ylabel "Speedup in Pourcentage (higher is better)"
plot "serial_vprec_full_denormal_speedup.txt" u 2:xtic(1) t "Serial implementation",\
     "vector_vprec_full_denormal_speedup.txt" u 2:xtic(1) t "Vector implementation",\
     "vprec_full_denormal_speedup.txt" u 2:xtic(1) t "Vector / Serial"

unset multiplot
