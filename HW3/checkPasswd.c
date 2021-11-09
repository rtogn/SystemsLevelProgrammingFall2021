#include <stdio.h>
#include <string.h>

// Enumerator for types of characters we are looking at
enum charType {decimal, Lcase, Ucase, Consecutive, None=-1};

int* num_nums(char* psswrd);
int calc_score(int* results, int sizeOf); 
int calc_consecutive(char* passwrd);
int is_same_type(char* a, char* b);
int type(char* cur); 
int calc_score(int* results, int sizeOf);


int main() {
	// Get user input up to 40 chars
	
	printf("Please enter a password:\n");
	char usr_password[40];
	if(fgets(usr_password, 40, stdin)) 
		usr_password[strcspn(usr_password, "\n")] = 0;
	
	int* results;
	results = num_nums(usr_password);
	int score = calc_score(results, 4);

	char* safety = (score >= 70)?"safe":"unsafe";
	
	printf("Your password is %s. It received a score of %d out of 100.\n", safety, score);


}

int* num_nums(char* psswrd) {
	// Returns array pointer with number of digits, lower case and upper case letters respectively.
	// Was named num_nums as originally only returned # of decimals but it was funny so I left it as is. 	
	// Set up inital values to zero for each
	int num_consec = 0;


	int curType;
	char* cur = psswrd;
	// Static array created as it needs to exist post scope of function. 
	static int results[4];
	// Initialize all positions to 0.
	results[decimal] = 0;
	results[Lcase] = 0;
	results[Ucase] = 0;	
	// Check pointer until null term. 
	while (*cur != '\0') {
		// Get type of current char ( enum charType decimal, Lcase, Ucase) 		
		curType = type(cur); 
		// Increment array position for that respective type
		if (curType != None)
			results[curType]++;
		// Increment current character pointer.
		cur++;
	}
	// Set value for existence of consecutive chars and return pointer to first value. 
	results[Consecutive] = calc_consecutive(psswrd);
	return results;
}

int calc_consecutive(char* passwrd) {
	// Condition: not consecutive case of 3 or more of the same type of letter (aaa=no aaa=yes
	// If 3 consecutive return 0, esle 1. This is due to how existence is scored.
	
	// Sinnce a word of less than 3 letters cant match condition, just return.
	if (strlen(passwrd) < 3) return 1;

	// Set up pointers for current char and two consecutive.
	char* cur = passwrd; //Current character
	char* next = cur + 1; //One ahead
	char* nextNext = cur + 2; //Two ahead

	// While loop breaks when 2nd character reaches \0. this rpevents erroneous data from being checked. 
	while (*nextNext != '\0') {
		// If current char matches the type of the next two return 0.
		if (is_same_type(cur, next) && is_same_type(cur, nextNext))
			return 0;
		cur++;
		next++;
		nextNext++;			
	}
	// Finally return 1 if no condition encountered. 
	return 1;
}

int is_same_type(char* a, char* b) {
	// Boolean check for if two characters are of the same type.
	return type(a) == type(b);
}

int type(char* cur) {
	// Returns value representing what type of character. decimal=0, Ucase=2, Lcase=1 else return -1.
	// Takes advantage of ranges of integer representations of chars in table. 
	if ( (int)*cur >= 48 && (int)*cur <= 57) return decimal;

	else if ( (int)*cur >= 65 && (int)*cur <= 90) return Ucase;

	else if ( (int)*cur >= 97 && (int)*cur <= 122) return Lcase;
	// If type is not covered, return None. 
	else return None;
}

int calc_score(int* results, int sizeOf) {
	// For each value in results array subtract 20
	// Size of array must be passed as discrete value to know end. 
	int score = 100;
	int* res = results;
	// fin is the end point of the loop determined by sizeOf
	int* fin = res + sizeOf;	
	for (res; res < fin; res++) { 
		// If a value is 0 (no chars of that type in password) decrease score by 20.
		if (!*res) 
			score -= 20;
	}
	return score;
} 
