#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	int i, j = 0;
	//goes through the entire source
	for (i = 0; i < size; i++){
		//if the value at source[i] is not 0, record the value and position
		if (source[i] != 0){
			pos[j] = i;
			val[j] = source[i];
			j++; //j keeps track of index of pos and val
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	int i, j;
	//goes on until end of array source
    for (i = 0, j = 0; i < m; i++){
    	//if counter i is equal to a value in val, use that value in pos and add to source
    	if(pos[j] == i){
    		source[i] = val[j];
    		j++;
    	}
    	//if no value in val equal to i, add 0 to source at i
		else{
			source[i] = 0;
		}
    }
}
