#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"
#define N2 3


int is_diag_dom(int mat[][N2]){

	int isDiag = 1, rowSum = 0, diagNum = 0, j, k;
	
	for (j = 0; j < N2; j++){//changes rows
		rowSum = 0;
		diagNum = fabs(mat[j][j]); //saves abs of diag of each row
		//sums the abs of other elements in row
		for (k = 0; k < N2; k++){
			if (j != k){
				rowSum += fabs(mat[j][k]);
			}
		}

		//if abs of diagNum is not larger than sum of abs rowSum, then isDiag is false adn 0 is returned
		if (diagNum <= rowSum){
			isDiag = 0;
			break;
		}
	}

    return isDiag;
}
