#include <stdio.h> 
 
int main() { 
 
	int letters; 
	int words; 
	int space = 0;
	char character; 
 
	printf("Enter a Sentence: "); 
	while((character=getchar()) != '\n') { 
		if(character != ' ') { 
			if(!space){ 
				words++; 
				space=1; 
				printf("words: %d \n ", words);
			}	 
			
			letters++;
			printf("letters: %d \n ", letters);
		} 
		else {			
			space = 0;
		} 
	}		 
printf("Average word length : %d\n", letters/words); 

return 0; 
}

