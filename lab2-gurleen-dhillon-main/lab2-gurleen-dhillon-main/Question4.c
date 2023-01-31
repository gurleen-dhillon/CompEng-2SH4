#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i, j;
	for (i = 0; word[i] != 0; i++){
		//for uppercase letters
		if(word[i] >= 65 && word[i] <= 90){
			j = word[i] - 65; //sets 'A' to 0 (start of freq array)
			freq[j]++; //increase count for letter
		}
		//for lowercase letters
		else if(word[i] >= 97 && word[i] <= 122){
			j = word[i] - 97; //sets 'a' to 0 (start of freq array)
			freq[j]++; //increase count for letter
	    }
	}
}
