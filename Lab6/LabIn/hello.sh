#!/bin/bash
#Script written by Robert Tognoni
#Email: rtognoni1@student.gsu.edu
echo "Welcome to the computer science society."
date
dirCount=`ls /home| wc -l`
echo "The number of directories in /home is: $dirCount"
echo -e "PATH: $PATH\nUSER: $USER\nSHELL: $SHELL\n"
echo "DISK USAGE REPORT: "
df
echo "END DISK USAGE REPORT."
echo "Please, could you loan me \$25.00"
echo "if x = 2, x * x = 4, x / 2 = 1"
ls | egrep '^c.*\.sh$'
hour=`date +%I`
echo "Good bye! The current hour is: $hour"
