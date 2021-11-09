#include <stdio.h>
#include <string.h>
void checkScore(char* passwrd);
int main() {
	// Get user input up to 40 chars
	// Since any password over 10 chars is automatically safe 
	// (and we arent storing it) we only need to set the buffer to 10+1
	printf("Please enter a password:\n");
	char usr_password[11];
	if(fgets(usr_password, 11, stdin)) 
		usr_password[strcspn(usr_password, "\n")] = 0;
	// Run check score function	
	checkScore(usr_password);
}

void checkScore(char* passwrd) {
        const int SAFE_LEN = 10;
	// Get length of current string
	int passwordLen = strlen(passwrd);
        char* result;
	// Calculate the deduction amount based on # of missing chars
        printf("passlen: %d\n", passwordLen);
	int deduction = 5*(SAFE_LEN - passwordLen);
	// Set output string based on deduction
        result = (deduction > 30)?"The password is unsafe! Please reset.":"The password is safe!";
       	// Print out results.
	printf("%s Deduction: %d\n", result, deduction);

}
