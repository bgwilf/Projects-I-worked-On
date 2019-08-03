/* 
 * File:   quizz1.cpp
 * Author: @Gilles Wilfried Bassole
 * Spring 2018-COSC 504
 * 
 * Quizz 1: Arrays -Feb. 15, 2018
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

const int NUMBER_OF_STUDENTS = 10;

void ReadGrades(double GradeList[]);
double CalculateAvg(double GradeList[ ]);
void printResults(double GradeList[ ]);  

//Reads the grades from keyboard and stores them in array GradeList 
void ReadGrades(double GradeList[]){
	for(int i=0; i < NUMBER_OF_STUDENTS; i++){
		int input=0;
		cout << "Enter grade for student "<< i+1<<" , for total out of a 100: " << endl;
		cin >> input;
		GradeList[i] = input;
	}
        cout << "\nThanks, all grades successfully stored!" << endl;
}

//Returns the average grade of all 10 students  
double CalculateAvg(double GradeList[ ]){
    double sumOfGrades = 0;
    
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        sumOfGrades += GradeList[i];
    }
    double Avg = sumOfGrades / NUMBER_OF_STUDENTS;
    
    return Avg;
}

//Prints each student’s grade and the class average grade 
void printResults(double GradeList[ ]){
    cout << "Students"<< setw(15) << "GradeBook" << endl;
    cout << endl;
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        cout <<"   "<< i+1 << setw(15)<< GradeList[i] <<endl; 
    }
  cout << "\nAverage Grade : "<< CalculateAvg(GradeList) <<endl;
  
}



/*
 * 
 */
int main(int argc, char** argv) {
    
    double GradeList[NUMBER_OF_STUDENTS]; 
    cout << " Hello :-) This cpp program records the grades, computes and prints ";
    cout << "\nthe average grade for all the student during the exam. "<< endl;
     
    ReadGrades(GradeList);
    cout << "\nNow Printing results ..." <<endl;
    printResults(GradeList);

    return 0;
}

