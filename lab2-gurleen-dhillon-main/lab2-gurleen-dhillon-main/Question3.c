#include <stdio.h>
#include <stdlib.h>
#define N3 3

#include "Questions.h"

void diag_scan(int mat [N3][N3], int arr [N3*N3]){

	int i, j, k, m, count = 0;
	//printing elements above and including diagonal
	for (i = 0; i < N3; i++){
		k = i;
		m = 0;
		//save values in array
		while(k >= 0){
			arr[count] = mat[k--][m++];
			count++;
		}
	}

	//printing elements below diagonal
	for (j = 1; j < N3; j++){
		k = N3-1;
		m = j;
		//save values in array
		while(m < N3) {
			arr[count] = mat[k--][m++];
			count++;
		}
	}
}
