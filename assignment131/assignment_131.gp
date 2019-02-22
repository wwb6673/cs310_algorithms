set key top left
set xlabel "Input Size"
set ylabel "Basic Operations"
f(x) = 1.5x**2 + 7.5x - 5
g(x) = x**2
plot 'assignment_131.dat' using 1:2 with points pointtype 7 \
         title 'assignment_131' noenhanced, \
       f(x) linewidth 2 title "1.5n^2", \
       g(x)  linewidth 2 title "n^2"



set key top left
set xlabel "Input Size"
set ylabel "Basic Operations"

plot 'assignment_131.dat' using 1:2 with points pointtype 7 \
         title 'assignment_131' noenhanced, \
       1.5*(x**2) + 7.5*x - 5 linewidth 2 title "1.5n^2 + 7.5n - 5", \
       x**2  linewidth 2 title "n^2", \
       5*(x**2) linewidth 2 title "5n^2"

set key top left
set xlabel "Input Size"
set ylabel "Basic Operations"

plot 'assignment_131_0.dat' using 1:2 with points pointtype 7 \
         title 'assignment_131' noenhanced, \
       x*(x+1)*0.5 linewidth 2 title "n(n+1)/2", \
       2*x linewidth 2 title "2n", \
       x linewidth 2 title "n"
