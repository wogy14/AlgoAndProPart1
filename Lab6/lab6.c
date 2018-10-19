#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define DEFAULT_LEN 255

int is_loud(char *c) {
	int arr[6] = { 'a','e','i','o','u','y'},i,j = 0,s;
	while (c[j] != '\0') {
		s = tolower(c[j]);		
		for (i = 0; i < 6; i++) if (s == arr[i]) return 1;
		j++;
	}	
	return 0;
}
int main() {
	char text[DEFAULT_LEN];
	int i = 0,c,str_len;
	printf("Put the string: ");
	fgets(text, DEFAULT_LEN, stdin);
	str_len = strlen(text);
	while (text[i] != '\0') {
		if (!isalpha(text[i]))	text[i] = '\0';
		i++;
	}
	char *p = text;	
	for (i = 0; i < str_len; i += c+1,p += c+1) {				
		if (p[i] == '\0') continue;		
		if (!is_loud(p)) printf("%s\n", p);
		c = strlen(p);		
	}	
	return 0;
}
