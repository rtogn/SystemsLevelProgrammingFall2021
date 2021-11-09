##!/bin/bash

#SEARCH MANUAL BY ROBERT TOGNONI rtognoni1@student.gsu.edu
man chmod cat vi ls grep mkdir rm awk sort tar pwd > mandatabase.txt

echo Please type the command you want to view the manual for
read uComm
#Convert input to upper case
uComm=`echo $uComm | tr [a-z] [A-Z]`
 
#Search for text in manual matching the entered item (between header and footer lines of the manual page)
x=`awk '/^('$uComm')/,/^[^('$uComm')].+('$uComm'\(1\))/ {print}' mandatabase.txt`
#If X is empty (no text found) then let user know that no item was found, else print the text. 
if [ -n "$x"]; then
	echo Sorry, I cannot help you 
else awk '/^('$uComm')/,/^[^('$uComm')].+('$uComm'\(1\))/ {print}' mandatabase.txt;
fi




