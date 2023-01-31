#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;



Matrix::Matrix(){
 rowsNum = 3;
 colsNum = 3;
 matrixData = NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}



Matrix::Matrix( int row, int col ){
	rowsNum = row;
	colsNum = col;
	matrixData = NULL;

	//if rowsNum or colsNum is less than or equal to 0, it is set to 3
	if (rowsNum <= 0){ rowsNum = 3; }
	if (colsNum <= 0){ colsNum = 3; }

	//allocate memory for matrixData
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	//Allocate rows for fake "2D array":
	for (int i = 0 ; i < rowsNum ; i++ ){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));
	}

	//set all elements in 2D matrix to 0
	for (int i = 0 ; i < rowsNum ; i++ ){
		for (int j = 0 ; j < colsNum ; j++ ){
			matrixData[i][j] = 0;
		}
	}
}



Matrix::Matrix(int row, int col, int** table){
	rowsNum = row;
	colsNum = col;
	matrixData = NULL;

	matrixData = (int**)malloc(rowsNum*sizeof(int*)); //allocate memory
	//Allocate rows for fake "2D array":
	for (int i = 0 ; i < rowsNum ; ++i ){
		matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	}

	//point to each element in 2D table array
	for (int i = 0; i < rowsNum; i++){
		for (int j = 0; j < colsNum; j++){
			matrixData[i][j] =* (*(table+i)+j); //assign element from table to matrix
		}
	}
}



int Matrix::getElement(int i, int j){
	int element = 0;
	//error message if i and j are out of bounds
	if(i >= rowsNum || i < 0 || j < 0 || j >= colsNum){
		throw std::out_of_range( "Invalid indexes." ); //return error
		return false;
	}
	//get and return element
	else{
		element = matrixData[i][j];
		return element;
	}
}



bool Matrix::setElement(int x, int i, int j){
	//check if i and j are valid indexes on this matrix
	if(i >= rowsNum || i < 0 || j < 0 || j >= colsNum){
		return false;
	}
	//setting element to the value of x
	else{
		matrixData[i][j] = x;
		return true;
	}
}



Matrix Matrix::copy(){
	 Matrix copy = Matrix(rowsNum,colsNum); //create copy of matrix
	 for (int i = 0; i < rowsNum; i++){
		 for (int j = 0; j < colsNum; j++){
			 copy.setElement(getElement(i,j), i, j); //copy over element into copy matrix
		 }
	 }
	 return  copy;
}



void Matrix::addTo( Matrix m ){
	int temp_addition = 0;
	//error message if matrices dont have same dimmension
	if((m.rowsNum != rowsNum) || (m.colsNum != colsNum)){
		throw std::invalid_argument("Invalid operation");
	}
	//adding matrix
	else {
		for (int i = 0; i < rowsNum; i++){
			for (int j = 0; j < colsNum; j++){
				temp_addition = (getElement(i,j) + m.getElement(i,j)); //add elements together
				setElement(temp_addition, i, j); //replace value with added version
			}
		}
	}
}



Matrix Matrix::subMatrix(int i, int j){
	Matrix subM = Matrix (i+1,j+1); //subM with size of row and col

	//error message if i and j out of bounds
	if(i >= rowsNum || i < 0 || j < 0 || j >= colsNum){
		throw std::out_of_range("Submatrix not defined");
	}
	//to create submatrix
	else {
		for (int row = 0; row < i+1; row++){
			for (int col = 0; col < j+1; col++){
				//set position (row,col) to the same value as element in original matrix at (row,col)
				subM.setElement(getElement(row,col), row, col);
			}
		}
	}
    return  subM;
}



int Matrix::getsizeofrows(){
	//update below return
	return -1;
}



int Matrix::getsizeofcols(){
	//update below return
    return -1;
}



bool Matrix::isUpperTr(){
	//goes through all elements below diagonal
	for (int i = 1; i < rowsNum; i++){
		for (int j = 0; j < i; j++){
			if(matrixData[i][j] != 0){
				return false; //not upper triangular
			}
		}
	}
	return true; //upper triangular
}



string Matrix::toString(){
	string output;

	for (int i = 0; i < rowsNum; i++){
		for (int j = 0; j < colsNum; j++){
			//convert each element to string and add a space
    		output+= to_string(matrixData[i][j]) + " ";
    	 }
    	output+="\n"; //add a new line for each row
     }
    return output;
}
