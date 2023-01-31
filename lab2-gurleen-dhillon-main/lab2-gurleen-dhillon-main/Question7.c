#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	int i, count1 = 0, count2 = 0;

	//loops until k1+k2 incase they don't share a position
	for (i = 0; i < (k1+k2); i++){

		//if pos1 and pos2 share a position and the sum is not 0, sum is added to val3 and position is added to pos3
		if ((pos1[count1] == pos2[count2]) && (val1[count1] + val2[count2] != 0)){
			val3[i] = val1[count1] + val2[count2];
			pos3[i] = pos2[count2];
			//count1 and count2 increases
			count2++;
			count1++;
		}

	    //if count2 is finished going through pos2, then pos1 and val1 at count1 get saved into pos3 and val3 & count1 increases
	    else if (k2 == count2){
	    	val3[i] = val1[count1];
	    	pos3[i] = pos1[count1];
	    	count1++;
	    }

	    //if count1 is finished going through pos1, then pos2 and val2 at count2 get saved into pos3 and val3 & count2 increases
	    else if (k1 == count1){
	    	val3[i] = val2[count2];
			pos3[i] = pos2[count2];
			count2++;
	    }

	    //if current pos# in pos 1 is smaller than pos2, then pos1 and val1 are saved in val3 and pos3 & count1 increases
		else if(pos1[count1] < pos2[count2]){
			val3[i] = val1[count1];
			pos3[i] = pos1[count1];
			count1++;
		}

	    //if current pos# in pos 2 is smaller than pos1, then pos2 and val2 are saved in val3 and pos3 & count2 increases
		else if(pos2[count2] < pos1[count1]){
			val3[i] = val2[count2];
			pos3[i] = pos2[count2];
			count2++;
		}

	    //break loop if all sumations are completed
	    if ((count1 == k1) && (count2 == k2)){ break; }
	}
}

