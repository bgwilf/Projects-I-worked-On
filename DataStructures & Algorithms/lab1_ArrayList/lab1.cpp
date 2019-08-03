/* 
 * File:   lab1.cpp
 * Author: @Gilles Wilfried Bassole
 * Spring 2018-COSC 504
 * 
 * Laboratory 1: Arrays -Feb. 8, 2018
 *
 * Created on February 12, 2018, 1:27 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void InitializeArray(int arrayList[], int size);
int findLargest(int arrayList[], int size);
int findSmallest(int arrayList[], int size);
void printList(int arrayList[], int size);

// -  reads the integers into the array
void InitializeArray(int arrayList[], int size){
	for(int i=0; i < size; i++){
		int input=0;
		cout << "Enter the "<< i+1<<" number of the array:" << endl;
		cin >> input;
		arrayList[i] = input;
	}
}

//-  returns the largest element in the array
int findLargest(int arrayList[], int size){
	int max = 0;
	for(int i=0; i < size; i++){
		if(arrayList[i] > max){
			max = arrayList[i];
		}
		
	}	
	return max;
}

//returns the smallest element in the array
int findSmallest(int arrayList[], int size){
	int min = arrayList[0];
		for(int i=1; i < size; i++){
		if(arrayList[i] < min){
			min = arrayList[i];
		}
	}	
	return min;
}

// – prints the elements in the array
void printList(int arrayList[], int size){
    cout << "Elements of the array entered are:" << endl;
	for(int i=0; i < size; i++){
		cout << arrayList[i] << endl;
	}
}


/*
 * Testing: Function called in main
 *  •	InitializeArray(int arrayList[], int size) -  reads the integers into the array
 *  •	int FindLargest(int arrayList[], int size) -  returns the largest element in the array
 *  •	int FindSmallest(int arrayList[], int size) – returns the smallest element in the array
 *  •	PrintList(int arrayList[], int size) – prints the elements in the array
 */
int main(int argc, char** argv) {
    
    int in;
    cout << "Enter array length now: ";
    cin >> in;
    int arrayList[in];	
    InitializeArray(arrayList, in);
    
    cout << "Largest number is: " << findLargest(arrayList, in) << endl;
    cout << "Smallest number is: " << findSmallest(arrayList, in) << endl;
    
    printList(arrayList, in);
    
return 0;
}


