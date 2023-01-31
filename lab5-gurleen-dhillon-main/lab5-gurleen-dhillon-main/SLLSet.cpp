#include "SLLSet.h"
#include <iostream>


SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}



SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size = arrSize;
	head = NULL;
	//count through sorted array backwards and save into linked list backwards (last element is saved as head
	for(int i = size-1; i >= 0; i--){
		SLLNode* node = new SLLNode;
		node->value = sortedArray[i];
        node->next = head;
        head = node;
	}
}



int SLLSet::getSize()
{
    return size;
}



SLLSet SLLSet::copy()
{
    SLLNode* node = new SLLNode(head->value,NULL);
    SLLSet *copy = new SLLSet();
    SLLNode* new_head = head;

    new_head = new_head->next;
    copy->size = size;
    copy->head = node;

    //loop through head and node values and save head value into node value
    while(new_head!=NULL){
        node->next = new SLLNode(new_head->value,NULL);
        new_head = new_head->next;
        node = node->next;
    }
    return *copy;
}



bool SLLSet::isIn(int v)
{
	int size = getSize();
	SLLNode *new_head = head;
	//determines if v is in array at any position
	for (int i = 0; i < size; i++){
		if (v == new_head->value){
			return true;
		}
		new_head = new_head->next; //to loop through all positions in head
	}
	return false;
}



void SLLSet::add(int v)
{
	SLLNode *new_head = head;
	if (isIn(v) == false){
		//to insert at the start (if list is empty)
		if (head == NULL){
			head = new SLLNode(v,NULL);
		}
		//to insert at the start (if v is smaller than the smallest number on list)
		else if (head->value > v){
			head = new SLLNode(v,head);
		}
		else{
			while(new_head->next != NULL){
				//to insert anywhere else on list
				if(new_head->value < v && new_head->next->value > v){
					new_head->next = new SLLNode(v, new_head->next);
				}
				//to add a new node to the end
				if (v > new_head->value){
					new_head->next = new SLLNode(v,NULL);
				}
				new_head = new_head->next; //to loop through all positions in head
			}
		}
		size++;//increase size to update its properties
	}
}



void SLLSet::remove(int v)
{
	SLLNode* node = head;
	//only if v exists in list
	if (isIn(v) == true){
		//if there is a node and another one after it
		while(node && node->next){
			if(node->next->value == v){
				//skips that node to remove it
				node->next = node->next->next;
			}
			//go to next node looking for v (looping through list)
			else{
				node = node->next;
			}
		}
		//if the list starts off with v, head starts with the next element
		if(head->value == v){
			head = head->next;
		}
		size--; //decrease size to update its properties
	}
}



SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLSet *newSet = new SLLSet();
	//if s is empty, return copy of original
	if(s.head == NULL){
		*newSet = copy();
		return (*newSet);
	}
	//if original is empty, return copy of s
	if(head == NULL){
		*newSet = s.copy();
		return (*newSet);
	}
	//if both are not empty
	*newSet = copy();
	//add all elements from s into new copy of array (add function removes duplicates)
    while (s.head != NULL){
        (*newSet).add(s.head->value);
        s.head = s.head->next; //to loop through all positions in head
    }
    return *newSet;
}



SLLSet SLLSet::intersection(SLLSet s)
{
	SLLSet *newSet = new SLLSet();
	//if either array is empty, no intersection
    if(s.head == NULL || head == NULL){
		return *newSet;
	}

    int i = 0;
	while (s.head != NULL){
		//only adds value from head if it exists in s
		if(isIn(s.head->value) == true){
			(*newSet).add(s.head->value);
			i++;
		}
		s.head = s.head->next;//to loop through all positions in head
	}
	(*newSet).size = i; //change total size
	return *newSet;
}



SLLSet SLLSet::difference(SLLSet s)
{
    SLLSet *newSet = new SLLSet();
    int i = 0;
    SLLNode *new_head = head;
	while (new_head != NULL){
		//only adds value from head if it does not exist in s
        if(s.isIn(new_head->value) == false){
            (*newSet).add(new_head->value);
            i++;
        }
        new_head = new_head->next; //to loop through all positions in head
    }
    (*newSet).size = i; //change total size
    return *newSet;
}



SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	SLLSet *newSet = new SLLSet();
	//loops through every row of matrix and uses setUnion to add every row into one
	for (int i = 0; i < size; i++){
		*newSet = (*newSet).setUnion(sArray[i]);
	}
    return *(newSet);
}



string SLLSet::toString()
{
    string output;
    //adds a comma and space to the end of each value converted to a string
    while (head != NULL) {
          output += to_string(head->value) + ", ";
          head = head->next;
    }
    //to remove the last comma and space at the end
    if(!output.empty()){
    	output.resize(output.size() - 2);
    }
   return output;
}
