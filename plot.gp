set term png size 1900,1000 noenhanced font "Terminal,10"

set datafile separator ";"

set grid

set auto x

set key right top

set xlabel "Vector size variants"

set style data histogram
set style fill solid border -1
set boxwidth 0.9

set key spacing 2
set key box lt -1 lw 2

set xtic rotate by -45 scale 0

set border linewidth 2
#set terminal png background "#1b1c1d"

# IEEE BACKEND

set output "ieee.png"
set multiplot layout 2, 2 rowsfirst

set title "IEEE Backend"

set yrange[0:300]

set ylabel "Bandwidth in MFLOP Per Second (higher is better)"
plot "serial_ieee.txt" u 2:xtic(1) t "Serial implementation",                  \
     "vector_ieee.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "serial_ieee.txt" u 3:xtic(1) t "Serial floatX / Serial float",           \
     "vector_ieee.txt" u 3:xtic(1) t "Vector floatX / Serial float",           \
     "ieee_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

unset multiplot


# VPREC BACKEND

set output "vprec.png"
set multiplot layout 2, 2 rowsfirst

set title "VPREC Backend with normal number"

set yrange[0:150]

set ylabel "Bandwidth in MFLOP Per Second (higher is better)"
plot "serial_vprec_normal.txt" u 2:xtic(1) t "Serial implementation",          \
     "vector_vprec_normal.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "serial_vprec_normal.txt" u 3:xtic(1) t "Serial floatX / Serial float",   \
     "vector_vprec_normal.txt" u 3:xtic(1) t "Vector floatX / Vector float",   \
     "vprec_normal_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

set yrange[0:150]

set ylabel "Bandwidth in MFLOP Per Second (higher is better)"
plot "serial_vprec_denormal.txt" u 2:xtic(1) t "Serial implementation",        \
     "vector_vprec_denormal.txt" u 2:xtic(1) t "Vector implementation"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "serial_vprec_denormal.txt" u 3:xtic(1) t "Serial floatX / Serial float", \
     "vector_vprec_denormal.txt" u 3:xtic(1) t "Vector floatX / Vector float", \
     "vprec_denormal_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

unset multiplot


# Standart derivation

set arrow from -1,6 to 16,6 nohead linecolor "red" linewidth 5

# IEEE BACKEND
set output "ieee_stddev.png"

set title "IEEE Backend standart derivation"

set yrange[0:100]

set ylabel "Standart derivation in % (lower is better)"
plot "serial_ieee.txt" u 4:xtic(1) t "Serial implementation",                  \
     "vector_ieee.txt" u 4:xtic(1) t "Vector implementation"

# VPREC BACKEND

set output "vprec_normal_stddev.png"

set title "VPREC Backend standart derivation with normal number"

set yrange[0:100]

set ylabel "Standart derivation in % (lower is better)"
plot "serial_vprec_normal.txt" u 4:xtic(1) t "Serial implementation",          \
     "vector_vprec_normal.txt" u 4:xtic(1) t "Vector implementation"

set output "vprec_denormal_stddev.png"

set title "VPREC Backend standart derivation with denormal number"

set yrange[0:100]

set ylabel "Standart derivation in % (lower is better)"
plot "serial_vprec_denormal.txt" u 4:xtic(1) t "Serial implementation",        \
     "vector_vprec_denormal.txt" u 4:xtic(1) t "Vector implementation"
