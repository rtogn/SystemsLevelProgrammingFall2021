#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BUFFER = 100;


void str_to_lower(char* str);
int is_palindrome(char* str);
int is_letter(char c); 
//HW4 Robert Tognoni
// Described a palindrome as any set of characters reading the same forwards as backwards
// Any spaces, numbers or special chars are ignored in this case so 'aab, baa'would be considerd one.
int main() {
	printf("Enter text to check (spaces/symbols will be ignored):\n");
	char usr_input[BUFFER];
	if(fgets(usr_input, BUFFER, stdin))
		usr_input[strcspn(usr_input, "\n")] = 0;
	char* message;
	message = is_palindrome(usr_input)?"is a palindrome":"is not a palindrome";

	printf("The text you entered (%s) %s\n", usr_input, message);	
}

void str_to_lower(char* str) {
// Removes special chars, spaces and makes all letters lowercase. 
	char* ptr = str;
	while (*ptr != '\0') {
		*ptr = tolower(*ptr);
		ptr++;
	}
}

int is_letter(char c) {
	// Check if item is a letter (only need lcase here)
	return ((int)c >= 97 && (int)c <= 122);

}

int is_palindrome(char* str) {
	str_to_lower(str);
	char* left = str;
	char* right = str + strlen(str)-1;
	while (*left != '\0' && right >= str ) {
		
		// Skip non characters. If reach end/beginning of string break and return false.
		while(!is_letter(*right)) {
			right--;
			if (right <= str) return 0;
		}
		while(!is_letter(*left)) {
			left++;
			if (*left == '\0') return 0;
		}
		// If characters dont match return 0.	
		if (*left != *right) return 0;			
		
		left++;
		right--;
	}
	return 1;	
}

