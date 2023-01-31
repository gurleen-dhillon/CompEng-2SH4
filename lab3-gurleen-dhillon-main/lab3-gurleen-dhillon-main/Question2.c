#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

student **create_class_list(char *filename, int *sizePtr){
	FILE *fp = fopen(filename, "r");
	int i, n;
	student **class_list;
	//file error
	if (fp == NULL){
		printf("Error:could not open the file %s\n", filename);
		exit(1);
	}
	fscanf(fp, "%d", &n);
	*sizePtr = n; //set size for class list
	class_list = (student **)malloc(n*(sizeof(student *))); //allocate space for class list
	//add in student info for each spot in class list
	for (i = 0; i < n; i++){
		class_list[i] = (student *)malloc(sizeof(student));
		fscanf(fp, "%d %s %s", &class_list[i] ->student_id, class_list[i]->first_name,class_list[i]->last_name);
		//initialize and set all grade to 0
		class_list[i]->project1_grade = 0;
		class_list[i]->project2_grade = 0;
		class_list[i]->final_grade = 0;
	}
	//close file and return classlist
	fclose(fp);
	return class_list;
}



int find(int idNo, student **list, int size)
{
	int i;
	//finds student_is in classlist
	for (i = 0; i < size; i++){
		if (list[i]->student_id == idNo){
			return i;//returns spot of id
		}
	}
	return -1;//id not in list
}



void input_grades(char *filename, student **list, int size)
{
	FILE *fp = fopen(filename, "r");
	int i, student_id, grade1,grade2;
	//file error
	if (fp == NULL){
		printf("Error: could not open the file %s \n", filename);
		exit(1);
	}
	//updates grade1 and grade2 from input numbers
	while (fscanf(fp,"%d",&student_id) == 1){
		fscanf(fp,  "%d %d", &grade1, &grade2);
		i = find(student_id, list, size);
		if (i != -1){
			list[i]->project1_grade = grade1;
			list[i]->project2_grade = grade2;
		}
	}
	fclose(fp);
}



void compute_final_course_grades(student **list, int size)
{
	//adds project 1 and 2 grades and divides by 2.0 (in case of decimals) for final grade for each student
	for (int i = 0; i < size; i++){
		list[i]->final_grade = (list[i]->project1_grade + list[i]->project2_grade) / 2.0;
	}
}



void output_final_course_grades(char *filename, student **list, int size)
{
	FILE *fp = fopen(filename, "w");
	//file error
	if (fp == NULL){
		printf("Error: could not open the file %s \n", filename);
	}
	//goes through classlist, prints final grade of each student and their id
	fprintf(fp, "%d \n", size);
	for (int i = 0; i < size; i++){
		fprintf(fp, "%d %.2f\n", list[i]->student_id, list[i]->final_grade);
	}
	fclose(fp);
}



void withdraw(int idNo, student **list, int* sizePtr)
{
	int equals_idNo = 0, i;
	//goes through list to see if idNo in it
	for (i = 0; i < *sizePtr; i++){
		if (list[i]->student_id == idNo){
			equals_idNo = 1;
			break;
		}
	}
	//removes student idNo from class list and shifts all others to fill in the gap
	if (equals_idNo){
		free(list[i]);
		for (i = i+1; i < *sizePtr; i++){
			list[i-1] = list[i];
		}
		(*sizePtr)--;
		printf("student id %d removed \n", idNo);
	}
	//if student idNo not found on class list
	else{
		printf("student id %d not found \n", idNo);
	}
}



void destroy_list(student **list, int *sizePtr)
{
	int i;
	//free up each section of list
	for (i = 0; i < *sizePtr; i++){
		free(list[i]);
	}
	*sizePtr = 0; //set the size to 0 (because it cleared up)
}
