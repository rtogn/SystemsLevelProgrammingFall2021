#!/bin/bash
#SIMPLE CALCULATOR BY ROBERT TOGNONI rtognoni1@student.gsu.edu
echo '*******************************************************************************************'
echo '                            WELCOME TO THE INLINE CALCULATOR                               '
echo *Enter a mathematical three character expression separated by spaces. Example: 1 + 2
echo '*Accepted operators: +(add) -(subtract) *(multiply) /(divide) %(modulo)'
echo *Special commands: Type CANC to exit
echo *Type ANS for either value to substitute in the previous answer. Example: ANS + 2 or 2 + ANS
echo *Type CLEAR clear the screen
echo '*******************************************************************************************'
#read user input
ans=0
check="ANS"
while [ true ]; do
	read statement
	#set each item to a variable, Number a, number b and operand o
	a=`echo "$statement" | awk '{print $1}'`
	o=`echo "$statement" | awk '{print $2}'`
	b=`echo "$statement" | awk '{print $3}'`
	
	# Set A and B to ANS, handle CANC option
	if [ "$a" == "ANS" ]
		then a="$ans"
	elif [ "$a" == "CANC" ] 
		then break
	fi


	if [ "$b" == "ANS" ];
		then b="$ans"
	fi

	# handle CLEAR option
	if [ "$a" == "CLEAR" ];
		then
		clear
	# Process expressions using bc for float and expr for integer mod. 
	elif [ "$o" == "%" ]
		then
		ans1=`expr "$a" "$o" "$b"`
		echo $ans1
	else 
		ans2=`echo "scale=2;$a$o$b" | bc`
		echo "$ans2"
	fi 
done
echo Thank you for useing Inline Calculator!
