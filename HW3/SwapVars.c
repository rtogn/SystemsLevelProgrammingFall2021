#include <stdio.h>
#include <string.h>

void swapChars(char* a, char* b);
int isAlpha(char a);
int isNumeric(char a);
void swapStrings(char* A, char* B);

int main() {
	

	char A[] = "a-ABC123";
	char B[] = "b-321CBA";
	
	printf("Before: A: %s, B: %s\n\n", A, B);
	swapStrings(A, B);
	printf("After: A: %s, B: %s\n\n", A, B);

}


int isNumeric(char a) {
// Returns if character is numeric (0-9)
	return (int)a >= 48 && (int)a <= 57;
}

int isAlpha(char a) {
// Returns if character is alphabetical (a-zA-Z)
	return (int)tolower(a) >= 97 && (int)tolower(a) <= 122;
}

void swapStrings(char* A, char* B) {
	char* a = A;
	char* b = B;
	while (*a != '\0') {
		// Swap individual characters if its parallel in the other string
		// is of the opposite type (numeric vs alpha.
		if (isNumeric(*a) && isAlpha(*b)) {
			swapChars(a, b);
		}
		else if (isAlpha(*a) && isNumeric(*b)) {
			swapChars(a, b);
		}
		// Increment both pointers in sync. 
		a++;
		b++;
	}
}

void swapChars(char* a, char* b) {
	// Swaps chars by simple arithmetic. 
	// Originally I tried to do this same algorithm with the mem addresses...it worked but I cant set
	// the values without another variable.
	// Example: a= 2, b =6
	// 1: a = 2 + 6 => a = 8
	// 2: b = 8-6 = 2 (swapped)
	// 3: a = 8-2 = 6 (swapped)	
	
	*a =(char)((int)*a+(int)*b);
	*b = (char)((int)*a-(int)*b);
	*a = (char)((int)*a-(int)*b);
}

