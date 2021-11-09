#include<stdio.h>

int main() {
	int a,b,c;
	printf("Enter phone number [(999)999-9999]: ");
	// %*c means do not assign character to any variable.
	scanf("%*c %d %*c %d %*c %d", &a, &b, &c);
	printf("%d-%d-%d\n", a, b, c);
}
