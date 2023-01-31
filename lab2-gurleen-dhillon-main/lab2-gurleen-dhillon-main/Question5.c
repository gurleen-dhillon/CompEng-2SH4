#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	int i;
	for (i = 0; i < n-1; i++){
		//copies over source to destination, excpet for the last index
		destination[i] = source[i];
	}
	destination[n-1] = '\0'; //puts a null in the last index of destination
}
