#include <cstdlib>
#include "doubleLinkedList_2.h"
//#include "Person.h"
using namespace std;


int main(int argc, char** argv) {
    
    doublyLinkedList<int> randList, listcopy;        
    int num;                                   

    cout << "Line 7: Enter numbers ending "
         << "with -999." << endl;               
    cin >> num;                                 

    while (num != -999)                        
    {                                           
        randList.insert(num);                      
        cin >> num;                             
    }                                           

    cout << endl;                               

    cout << "Line 15: list1: ";                 
    randList.print();                              
    cout << endl;                              

    listcopy = randList; //test the assignment operator 

    cout << "Line 19: list2: ";                 
    listcopy.print();                              //Line 20
    cout << endl;                               //Line 21

    cout << "Line 22: Enter the number to be "
         << "deleted: ";                        //Line 22
    cin >> num;                                 //Line 23
    cout << endl;                               //Line 24

    listcopy.deleteNode(num);                      //Line 25


    return 0;
}

