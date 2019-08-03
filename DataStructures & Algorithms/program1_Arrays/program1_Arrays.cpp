/* 
 * File:   program1_Arrays.cpp
 * Author: @Gilles Wilfried Bassole
 * Spring 2018-COSC 504
 * 
 * Programming Assignment 1: Arrays -Feb. 12, 2018

 * Write a program that allows the user to enter the last names of five candidates
 * in a local election and the number of votes received by each candidate. The 
 * program should then output each candidate’s name, the number of votes
 * received, and the percentage of the total votes received by the candidate. 
 * Your program should also output the winner of the election.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int NUMBER_OF_CANDIDATES = 5;

int findWinner(int votes[]);
void printResults(string candidates[], int votes[]);
double calculatePercentage(int votes[], int vote);

/* 
 * Computes percentage of votes received by each individual candidates
 * 
 * returns percentage
 */
double calculatePercentage(int votes[], int vote){
    int sumOfVotes = 0;
    
    for (int i = 0; i < NUMBER_OF_CANDIDATES; i++) {
        sumOfVotes += votes[i];
    }
    
    double percentage = static_cast<double>(vote) / sumOfVotes;
    
    return percentage*100;
}

/*
 * Function used to find the candidates with the most votes
 * inputs array {Votes[]}
 * returns index of the candidate with the most votes 
*/
int findWinner(int votes[]){
    int winner = 0;
    int ivote= votes[0];
    for (int i = 1; i < NUMBER_OF_CANDIDATES; i++) {
        if (votes[i] > ivote){
            winner = i;
            ivote= votes[i];
        }

    }
    return winner;
}

/*
 * Prints out the info in the format indicated with total votes
 * And winner of the Election
 */
void printResults(string candidates[], int votes[]){
   int total= 0;
    cout << "Candidates" << setw(30) << "Votes Received" << setw(30) << "% of Total Votes" << endl;
    cout << endl;
    
    for (int i = 0; i < NUMBER_OF_CANDIDATES; i++) {
        total += votes[i];
        cout << candidates[i] << setw(30) << votes[i] << setw(30); 
        double percentage = calculatePercentage(votes, votes[i]);
        cout << percentage << endl;                     //"%" << endl;
        cout << endl;
    }
    cout << "TOTAL :" << setw(30) << total <<endl;
}

/*
 * Function called in main
 * •    int findWinner(int votes[]);
 * •    void printResults(string candidates[], int votes[]);
 * •    double calculatePercentage(int votes[], int vote);
 * 
 */
int main(int argc, char** argv) {
    string candidates[NUMBER_OF_CANDIDATES];
    int votes[NUMBER_OF_CANDIDATES];
    
    cout << "Please input the 5 candidates followed by the votes they received-i.e. helena 850 -: ";
    for (int i = 0; i < NUMBER_OF_CANDIDATES; i++) {
        cin >> candidates[i] >> votes[i];
    }
    printResults(candidates, votes);
    cout << endl;
    cout << "The Winner of the Election is: " << candidates[findWinner(votes)] << endl;
    return 0;
}