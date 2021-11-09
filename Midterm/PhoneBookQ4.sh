#!/bin/bash
#PHONE BOOK BY ROBERT TOGNONI rtognoni1@student.gsu.edu

echo '*******************************************************************************************'
echo '                            WELCOME TO THE PHONE BOOK                              '
echo '*TYPE read, read all, edit, delete, or exit'
echo '*read: will prompt for a specific entry. Enter the desired name to see address and phone.'
echo *add: Will prompt you to create a new entry
echo *delete: Will prompt for a name. Enter the desired name to remove it from the phoen book
echo *edit: Will prompt for a name. Enter the desired name to edit its contents. Must match a current entry
echo '*******************************************************************************************'

# Create txt file if it does not exit.
>>phonebook.txt

while [ true ]; do
	# Prompt user and save input.
	echo "Enter your command: read, add, edit, delete or exit"
	read prompt
	
	if [ "$prompt" == "exit" ]
		then break
	
	elif [ "$prompt" == "read" ] 
		then 
		echo "Displaying contents of phonebook..."
		echo "Format: |  Name  | Address | PhoneNum |"
		# Display contents of phonebook sorted by name
		grep -v '^$' phonebook.txt | sort -b 
	
	elif [ "$prompt" == "edit" ] 
		then 
		echo "Please enter the name you want to edit"
		read eName
		# Check if request exists in file with grep -c to count
		check=`grep -c "^| $eName |" phonebook.txt`
		# If there is an entry proceed, else let user know to try again
		if [ "$check" -gt 0 ]
			then
			echo "The Current entry reads: "
			grep "$eName" phonebook.txt 	
			read -p "Enter their new Name: " eNewName
			read -p "Enter their new address: " eAddress
			read -p "Enter their new phone number: " eNumber
			eChange=`echo '|' $eNewName '|' $eAddress '|' $eNumber '|'`
			#echo eChange- $eChange
			echo eName: $eName
			echo eChange: $eChange
			sed -i  "s/| $eName |.* |.*/$eChange/g" phonebook.txt	
			echo $eName updated to $eChange
		else echo "Entry not found, try again."
		fi	
	
	elif [ "$prompt" == "add" ] 
		then 		
		echo "Please enter the contact name"
		read -p "Enter their Name:" aName
		
		check=`grep -c "$aName" phonebook.txt`
		if [ "$check" -gt 0 ]
			then
			echo "This name already exists."
		else
			read -p "Enter their address:" aAddress
			read -p "Enter their phone number:" aNumber
			aEntry=`echo '|' $aName '|' $aAddress '|' $aNumber '|'`
			echo $aEntry >> phonebook.txt
			echo $aName has been added.
		fi
	
	elif [ "$prompt" == "delete" ]
		then
		echo "Please enter the name you want to delete"
		read toDelete	
		check=`grep -c "$toDelete" phonebook.txt`

		if [ "$check" -gt 0 ]
			then
			sed -i "s/| $toDelete |.* |.*//g" phonebook.txt	
			echo $toDelete has been removed!
		else echo "Entry not foud, try again"
		fi
	
	elif [ "$prompt" == "clear" ]
		then
		clear

	else echo "That is not a valid option, try again."
	fi
done
