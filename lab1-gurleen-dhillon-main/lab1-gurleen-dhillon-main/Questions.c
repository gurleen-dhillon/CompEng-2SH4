#include "Questions.h"
#include <stdlib.h>


int Q1_for(){
	int sum = 0;
	for (int i = 30; i <= 1000;i++){ //range of 30 to 1000
		if (i%4 == 0){
			sum = sum+i; //adds only if divisible by 4
		}
	}
	return sum;
}



int Q1_while(){
	int sum = 0, i = 30;
	while (i <= 1000){ //from range 30 to 1000
		if (i%4 == 0){
			sum = sum+i; //adds only if divisible by 4
		}
		i++;
	}
	return sum;
}



int Q1_do(){
	int sum = 0, i = 30;
	do {
		if (i%4 == 0){
			sum = sum+i; //adds only if divisible by 4
		}
    i++;
	} while(i <= 1000); //from range 30 to 1000
	return sum;
}


//=============================================================================================================================


int Q2(int Q2_input){
	int IsFiveDigit;
	Q2_input = abs(Q2_input); //takes absolute of number in case it is negative
	//dividing by 10000 will get an integer number equal to 1 or higher and less than 10 if it has 5 digits
	if ((Q2_input/10000 >= 1) && (Q2_input/10000 <10)){
		IsFiveDigit = 1;//5 digits
	}
	else {
		IsFiveDigit = 0;//not 5 digits
	}
	return IsFiveDigit;
}


//===============================================================================================


int Q3(float Q3_input){
	float GPA;
	if (Q3_input > 100){ GPA = -1; } //if mark higher than 100
	else if (Q3_input >= 90){ GPA = 4; }//mark between 90-100
	else if (Q3_input >= 80){ GPA = 3; }//mark between 80-89
	else if (Q3_input >= 70){ GPA = 2; }//mark between 70-79
	else if (Q3_input >= 60){ GPA = 1; }//mark between 60-69
	else if (Q3_input >= 0){ GPA = 0; }//mark between 0-59
	else{ GPA = -1;	}//if mark lower than 0
	return GPA;	
}


//===============================================================================================


double Q4(int Q4_input){
	double pi = 0, den = 1;

	for (int i = 1; i <= Q4_input; i++){ //goes through loop Q4_input times
		//switch signs of term being added every other time
		if (i%2 == 1){
			pi = pi + (4/den);//add 4/denominator
		}
		else{
			pi = pi - (4/den);//subtract 4/denominator
		}
		den = den+2;//increase denominator by 2 each time
	}

	return pi;	
}


//===============================================================================================


int Q5(){

	int totNumTribles=0;
	
	for (int side2 = 1; side2 <= 400; side2++){ //side2 <= 400
		for(int side1 = 1; side1 <= side2; side1++){ //side1 <= side2
			for(int hyp = 1; hyp <= 400; hyp++){ //hypotenuse <= 400
				if ((side1*side1 + side2*side2) == (hyp*hyp)){ //a^2 + b^2 = c^2
					totNumTribles++; //if all conditions are met by the random number generating loops, totNumTribles has 1 added to it
				}
			}
		}
	}

	return totNumTribles;
}


//===============================================================================================


int Q6(int Q6_input, int perfect[]){

	int counts = 0, tot, i, x;

	//if negative, returns 0
	if (Q6_input < 0){
		return 0;
	}

	for(x = 1; x <= Q6_input; x++){
		for(i = 1, tot = 0; i < x; i++){
			if (x%i == 0) {
				tot = tot + i;
			}
		}
		if (tot == x){
			perfect[counts] = x;
			counts++;
		}
	}
	return counts;
}


//===============================================================================================


int Q7a(int Q7_input){

	Q7_input = abs(Q7_input);//if number negative, makes it positive
	
	int reversedInt = 0;
	for (int i = 1; i <= 7; i++){ //goes through loop 7 times for 7 digits
		//takes away last digit of input, add to previous reverseInt, multiples by 10 to add another place value at end
		reversedInt = reversedInt * 10 + Q7_input % 10;
		Q7_input = Q7_input / 10;
	}
	return reversedInt;
}



int Q7b(int Q7b_input){
	
	if (Q7b_input < 0){
		Q7b_input *= -1;
	}

	int reversedInt = 0;
	while (Q7b_input > 0) { //goes on until input is all sorted
		//takes away last digit of input, add to previous reverseInt, multiples by 10 to add another place value at end
		reversedInt = reversedInt * 10 + Q7b_input % 10;
		Q7b_input = Q7b_input / 10;
	}
	return reversedInt;
}
