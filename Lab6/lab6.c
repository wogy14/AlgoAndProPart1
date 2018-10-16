#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define DEFAULT_LEN 255

int is_loud(char c) {
	int arr[6] = { 'a','e','i','o','u','y' }, i = 0;
	c = tolower(c);
	for (i = 0; i < 6; i++) {
		if (c == arr[i]) {
			return 1;
		}
	}
	return 0;
}
int main() {
	char text[DEFAULT_LEN];
	int i = 0,count = 0;
	printf("Put the string: ");
	fgets(text, DEFAULT_LEN, stdin);	
	while (text[i] != '\0') {
		if (text[i] == ' ' || text[i] == '.' || text[i] == '\n') {
			text[i] = '\0';
		}		
		i++;
	}
	for (i = 0; i < DEFAULT_LEN;i++) {
		int checker = 1,start = i;
		while (text[i] != '\0') {		    
			if (!isalpha(text[i])) {
				checker = 0;
			}
			if (is_loud(text[i])) {
				checker = 0;
			}
			i++;
		}
		if (checker && isalpha(text[start])) {			
			printf("%i. ",++count);
			while (text[start] != '\0') {
				printf("%c",text[start]);
				start++;
			}
			printf("\n");
		}
	}
	return 0;
}
