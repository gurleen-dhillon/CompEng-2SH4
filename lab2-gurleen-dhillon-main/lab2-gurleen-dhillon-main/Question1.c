#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
	int i;
	//adds elements from v1 and v2 at i and saves in v3 at i
	for (i = 0; i < size; i++){
		vector3[i] = vector1[i] + vector2[i];
	}
}


double scalar_prod(double vector1[],double vector2[],int size)
{
    double prod = 0;
    int i;
    for (i = 0; i < size; i++){
    	prod += (vector1[i] * vector2[i]); //adds product of both vectors at i to prod
    }
    return prod;
}


double norm2(double vector1[], int size)
{
    double L2;
	L2 = sqrt(scalar_prod(vector1, vector1, size)); //square roots and then saves the scalar product of vector 1
    return L2;
}
