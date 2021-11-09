//Robert Tognoni
//Lab 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* strcpy1(char* strDest, char* strSrc);
int getStrLen(char* string);
char* getLargest(int breakPoint);

int main() {
	getLargest(4);
	return 0;
}

char* strcpy1(char* strDest, char* strSrc) {
	//char cu = '_';
	char* curDest = strDest;
	char* curSrc = strSrc;
	// Loop character until null terminator
	while (*curSrc != '\0') {
	// For char in source add it to destitnation.
		*curDest = *curSrc;
		curSrc++;
		curDest++;
	}
	// Finally: add null term to copy string.
	*++curDest = '\0';
}


int getStrLen(char* string) {
	// Returns the literal character length of a string (excluding null char)
	//int letCount = 0;
	//Didnt realize strlen already existed!
	char* cur = string;
	// Simple loop. Count chracters using a char pointer until we reach \0 and break. 	
	while (*cur != '\0') {
		cur++; 
		//letCount++;
	}
	return cur - string;
}


char* getLargest(int breakPoint) {
	char nextStr[20];
	char largest[20];
	char smallest[20];
	int len = 0;
	
	while (len != breakPoint) {
		printf("Enter a string. Type a %d letter word to break.:", breakPoint);
		
		// Use fgets to read a line. Since it adds a \n when user presses enter we replace 
		// it with a null term to prevent multiline strings.
		if(fgets(nextStr, 20, stdin)) 
			nextStr[strcspn(nextStr, "\n")] = '\0';
			
		// Update len to the current string to scan for a breakPoint: length string. 		
		len = getStrLen(nextStr);
	
		// Check if current entry is > or < than largest/smallest and overrite if so. 
		// Since smallest starts at 0 check for this case and overwrite if empty. .	
		if (strcmp(nextStr, largest) > 0) 
			strcpy(largest, nextStr);
		if (strcmp(nextStr, smallest) < 0 || getStrLen(smallest) == 0)
			strcpy(smallest, nextStr);			
	}
	printf("Smallest word: %s\nLargest word: %s\n", smallest, largest);
}
