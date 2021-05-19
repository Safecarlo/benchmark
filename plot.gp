set term png size 1900,1000 noenhanced font "Terminal,12"

set datafile separator ";"             # set separator to ;

set grid ytics                         # only horizontal grid (y)

set auto x

set key right top                      # legend

set style data histogram
set style fill solid border -1
set boxwidth 0.9

set ylabel font "Deja Vu,14"

set key spacing 1.5
set key box lt -1 lw 2

set xtic rotate by 45 right scale 0

set border linewidth 2

# IEEE BACKEND

set output "ieee.png"
set multiplot layout 2, 2 rowsfirst

set title "Bandwidth of IEEE Backend" font "Deja Vu,20"

set yrange[0:300]

set ylabel "Bandwidth in MFLOP/s (higher is better)"
plot "serial_ieee.txt" u 2:xtic(1) t "Master branch",                  \
     "vector_ieee.txt" u 2:xtic(1) t "Vector branch"

set title "Speedup of IEEE Backend"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "serial_ieee.txt" u 3:xtic(1) t "Serial floatX / float",           \
     "vector_ieee.txt" u 3:xtic(1) t "Vector floatX / float",           \
     "ieee_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

unset multiplot


# VPREC BACKEND

set output "vprec.png"
set multiplot layout 2, 2 rowsfirst

## normal
set title "Bandwidth of VPREC Backend with Normal number"

set yrange[0:150]

set ylabel "Bandwidth in MFLOP/s (higher is better)"
plot "serial_vprec_normal.txt" u 2:xtic(1) t "Master branch",          \
     "vector_vprec_normal.txt" u 2:xtic(1) t "Vector branch"

set title "Speedup of VPREC Backend with Normal number"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "serial_vprec_normal.txt" u 3:xtic(1) t "Serial floatX / float",   \
     "vector_vprec_normal.txt" u 3:xtic(1) t "Vector floatX / float",   \
     "vprec_normal_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

## denormal
set title "Bandwidth of VPREC Backend with Denormal number"

set yrange[0:150]

set ylabel "Bandwidth in MFLOP/s (higher is better)"
plot "serial_vprec_denormal.txt" u 2:xtic(1) t "Master branch",        \
     "vector_vprec_denormal.txt" u 2:xtic(1) t "Vector branch"

set title "Speedup of VPREC Backend with Denormal number"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "serial_vprec_denormal.txt" u 3:xtic(1) t "Serial floatX / float", \
     "vector_vprec_denormal.txt" u 3:xtic(1) t "Vector floatX / float", \
     "vprec_denormal_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

unset multiplot

## normal vector vs normal serial
set output "vprec_serial_vs_vector.png"
set multiplot layout 2, 2 rowsfirst

set title "Bandwidth of VPREC Backend with Normal number in Vector branch"

set yrange[0:150]

set ylabel "Bandwidth in MFLOP/s (higher is better)"
plot "normal_serial_vprec_normal.txt" u 2:xtic(1) t "Serial implementation",   \
     "vector_vprec_normal.txt" u 2:xtic(1) t "Vector implementation"

set title "Speedup of VPREC Backend with Normal number in Vector branch"

set yrange[0:8]

set ylabel "Speedup in % (higher is better)"
plot "normal_serial_vprec_normal.txt" u 3:xtic(1) t "Serial floatX / float", \
     "vector_vprec_normal.txt" u 3:xtic(1) t "Vector floatX / float",        \
     "serial_vprec_normal_speedup.txt" u 2:xtic(1) t "Vector floatX / Serial floatX"

unset multiplot

# Standard deviation

set arrow from -1,6 to 16,6 nohead linecolor "red" linewidth 5
set label "6" at -1.15,6

# IEEE BACKEND
set output "ieee_stddev.png"

set title "Standard deviation of IEEE Backend"

set yrange[0:100]

set ylabel "Standard deviation in % (lower is better)"
plot "serial_ieee.txt" u 4:xtic(1) t "Master branch",                  \
     "vector_ieee.txt" u 4:xtic(1) t "Vector branch",

# VPREC BACKEND

## normal
set output "vprec_normal_stddev.png"

set title "Standard deviation of VPREC Backend with Normal number"

set yrange[0:100]

set ylabel "Standard deviation in % (lower is better)"
plot "serial_vprec_normal.txt" u 4:xtic(1) t "Master branch",          \
     "vector_vprec_normal.txt" u 4:xtic(1) t "Vector branch"

## denormal
set output "vprec_denormal_stddev.png"

set title "Standard deviation of VPREC Backend with Denormal number"

set yrange[0:100]

set ylabel "Standard deviation in % (lower is better)"
plot "serial_vprec_denormal.txt" u 4:xtic(1) t "Master branch",        \
     "vector_vprec_denormal.txt" u 4:xtic(1) t "Vector branch"
