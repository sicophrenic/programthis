#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char* extend(char*,int);
int main(int argc, char** argv) {
	char* string = argv[1];
	char* key = argv[2];
	
	//printf("%s\n", string);
	//printf("%s\n", key);
	
	float slen = strlen(string);
	float klen = strlen(key);
	
	char* ref;
	if (slen > klen) {
		int duplicate = floor(ceil(slen/klen));
		ref = extend(key, duplicate);
	} else if (slen < klen) {
		char* destination = malloc(strlen(string)+1);
		ref = strncat(destination,key,strlen(string));
	} else {
		ref = key;
	}
	//printf("%s\n", ref);
	
	int i;
	char *rtn = malloc(strlen(string)+1);
	char nchar;
	
	for(i=0; i<strlen(string);i++) {
		nchar = string[i];
		if (isalpha(nchar)) {
			char schar = string[i]-'a';
			char kchar = ref[i]-'a';
			nchar = (schar+kchar)%26 + 'a';
		}
		rtn[i] = nchar;
	}
	
	printf("%s\n", rtn);
}

char* extend(char* key, int repeat) {
	char* temp = key;
	key = malloc(strlen(key)*repeat+1);
	strcpy(key, temp);
	while (repeat > 1) {
		strcat(key, temp);
		repeat--;
	}
	return key;
}