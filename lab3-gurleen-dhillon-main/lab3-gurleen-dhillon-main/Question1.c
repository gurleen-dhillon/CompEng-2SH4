#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"


char *my_strcat(const char * const str1, const char * const str2){
	char *z = NULL;
	//allocates room for size of both strings plus 1
	z = malloc(strlen(str1) + strlen(str2) + 1);
    //i counter to go through both strings one at a time
    //j counter for z to keep counting when done with str1
    //str# saves into z while checking if it hasnt ended yet
	int j=0;
	for(int i = 0; (z[j] = str1[i]) != '\0'; i++, j++){
	}

	for(int i = 0; (z[j] = str2[i]) != '\0'; i++, j++){
	}
	//return and free z
	return z;
	free(z);
}
