#!/bin/bash
#STATEMENT COUNTER TABULATED BY ROBERT TOGNONI rtognoni1@student.gsu.edu
#COUNT NUMBER OF SENTENCES IN THE GIVEN FILE
#1) Sed places every sentence on a new line by replacing . with ]n, 2) Grep counts non-blank slines. 
#3) Sed filters out non letter characters except space to maintain word count
#4) Use awk to cont line number (NR), word count which is the num of fields (NF) and then char count which is total len -number of spaces (word count+1)
echo "|Line#         |WordCount    |CharacterCount|"
sed 's/\./\.\n/g' myexamfile.txt |grep -E '.+\.$' | sed 's/[^.-zA-Z\d \s:]//g' | awk -F' ' '{print "|"NR "             |" NF "           |" length-NF+1"|"}'

#sed 's/\./\n/g' lipsum.txt | awk -F' ' '{print "|"NR "    |          " NF "|           " length"|"}'
