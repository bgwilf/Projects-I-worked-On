/* 
 * File:   lab2_linkedlist.cpp
 * Author: Wilfried
 *
 * Created on February 15, 2018, 3:42 PM
 */

#include <iostream>
#include <cstdlib>
using namespace std;


struct NodeType {
	int x;
	NodeType *next;
};

NodeType* buildListForward(NodeType* first);
NodeType* buildListBackward(NodeType* first);
void print(NodeType* first);

bool search(int key, NodeType* first);
NodeType* addNode(int key, NodeType* first);
NodeType* deleteList(NodeType* first);
NodeType* deleteNode(NodeType* first);

//– adds to the tail of the list
NodeType* buildListForward(NodeType* first) {
        //cout << "\nBuilding List of integers Forward...\n";
	cout << "\nPlease input your series of positive integers, Enter -1 to quit: \n";
	int numb;

	while (1) {
		cin >> numb;
		if (numb == -1) break;
                
		NodeType* newnode = new NodeType;
		newnode->x = numb;
		if (first == NULL){
			newnode->next = NULL;
			first = newnode;
		}
		else{
			NodeType* tmp = first;
			while (tmp->next != NULL)
				tmp = tmp->next;

			tmp->next = newnode;
			newnode->next = NULL;
		}
	}
	return first;
}

//– adds to the head of the list
NodeType* buildListBackward(NodeType* first) {       
	cout << "\nPlease input your series of positive integers, Enter -1 to quit: \n";
	int numb;

	while (1) {
		cin >> numb;
		if (numb == -1) break;

		NodeType* newnode = new NodeType;
		newnode->x = numb;
		if (first == NULL)
		{
			newnode->next = NULL;
			first = newnode;
		}
		else
		{
			newnode->next = first;
                	first = newnode;
		}
	}
        //cout << "\nBuilding List of integers Backward...\n";
	return first;
}

//– prints the values in the list on one line separated by spaces
void print(NodeType* first) {
	NodeType* newnode = first;
	while (newnode != NULL) {

		cout << newnode->x << " ";
		newnode = newnode->next;
	}
}



//– searches the list for a key value and returns true/false if the key is (not) in the list
bool search(int key, NodeType* first) {
	bool check = false;
        int count=0;

	NodeType* newnode = first;
	while (newnode != NULL) {
		if (newnode->x == key) {
			check = true;
                        count++;
			break;
		}
		newnode = newnode->next;
	}
        cout << count <<" Match(s) found!!"<<endl;
	return check;
}

//– add a single not to the end of the list
NodeType* addNode(int key, NodeType* first) {

	NodeType* newnode = new NodeType;
	newnode->x = key;
	if (first == NULL) {
		newnode->next = NULL;
		first = newnode;
	}
	else {

		NodeType* tmp = first;
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = newnode;
		newnode->next = NULL;
	}
        return first;
}

//– delete the entire list
NodeType* deleteList(NodeType* first) {
	NodeType* newnode = first;
	NodeType* tmp;

	while (newnode != NULL) {
		tmp = newnode->next;
		delete  newnode;
		newnode = tmp;
	}
	return newnode;
}

//– delete a node from the end of a list
NodeType* deleteNode(NodeType* first) {

	if (first->next == NULL) {
		delete first;
	}
	else {
		NodeType* current = first;
		NodeType *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		delete current;
	}
	return first;
}


int main()
{
    NodeType* list1 = NULL;
    NodeType* list2 = NULL;
        cout <<"Lets create 2 separate linked lists!"<< endl;
		
        cout << "\nIn List1, nodes are inserted at the front of the list.";
	list1 = buildListForward(list1);
        cout << "\nPrinting List1 : ";
        print(list1);
        cout<< endl;
        
	cout <<"\nlist 2, nodes are inserted at the end of the list.";
	list2 = buildListBackward(list2);
        cout << "\nPrinting List2 : ";
        print(list2);
        cout<<endl;
	
        cout << "\n***Lets check more functions implemented on list 1***\n";
        cout << "Please input a key value to be searched in list1: ";
        int key;
        cin >> key;
	cout << "\nSearching list1 for key value:  ";
        search(key, list1);
	
	cout <<"\nNow, lets add a single node to the end of the list.";
        cout << "Please input value for node: ";
        int key1;
        cin >> key1;
        list1 = addNode(key1, list1);
	cout <<"After adding node, list1 becomes: ";
        print(list1);
        cout<<endl;

	cout <<"\nLets now delete a node from end of list \n ";
        list1 = deleteNode(list1);
	cout << "...After last node deletion, list1 becomes: ";
        print(list1);
        cout<<endl;


	cout <<"\nFinally, we'll be deleting the list now ....";
        list1 = deleteList(list1);
	cout << "\nlist1 deletion completed!!!\n";
        print(list1);
        cout<<endl;
        
        
        cout <<"\nMANY Thanks for testing this c++ program!!\nBye -_- THE END." <<endl;

	
	return 0;
}
//system("pause");
