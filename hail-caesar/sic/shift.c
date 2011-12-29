#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv) {
	char* string = argv[1];
	int shift = atoi(argv[2]);
	
	//printf("%s, %d\n", string, shift);
	
	int i;
	char* rtn = malloc(strlen(string)+1);
	char nchar;
	for(i=0; i<strlen(string); i++) {
		nchar = string[i];
		if (isalpha(nchar)) {
			if (isupper(nchar)) {
				rtn[i] = ((nchar-'A')+shift)%26+'A';
			} else {
				rtn[i] = ((nchar-'a')+shift)%26+'a';
			}
		} else {
			rtn[i] = nchar;
		}
	}
	printf("%s\n", rtn);
}