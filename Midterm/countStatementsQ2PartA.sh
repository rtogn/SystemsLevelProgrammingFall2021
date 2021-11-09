#!/bin/bash
#STATEMENT COUNTER BY ROBERT TOGNONI rtognoni1@student.gsu.edu
#COUNT NUMBER OF SENTENCES IN THE GIVEN FILE
#1) Sed places every sentence on a new line by replacing . with ]n, 2) Greo counts non-blank slines. 
sed 's/\./\.\n/g' myexamfile.txt | grep -cE '.+\.$' 

