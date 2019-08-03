#include <cstdlib>
#include <iostream>
#include<stdio.h>

using namespace std;

struct nodeType {
	int info;
	nodeType *link;
};

struct btNode {
	int data;
	btNode * rt;
	btNode * lt;
};

btNode * node(int d) {
	btNode *n = new btNode;
	n->data = d;
	n->rt = NULL;
	n->lt = NULL;
	return n;
}

void BT(btNode *head, int n) {
	//if (root == NULL)
	//	root = node(n);
//	else
		//if (root->data > n)
		//	BT(root->rt, n);
		//else
		//	BT(root->lt, n);
}

void preorder(btNode * root)
{
	if (root != NULL) {
		cout << root->data << " ";
		preorder(root->lt);
		preorder(root->lt);
	}

}

nodeType* buildListBackward() {
	nodeType *first, *newNode;
	int num;

	cout << "Enter a list of integers ending with -999." << endl;
	cin >> num;
	first = NULL;

	while (num != -999)
	{
		newNode = new nodeType;
		newNode->info = num;
		newNode->link = first;

		first = newNode;

		cin >> num;
	}
	return first;
}//end function

int factorial (int n){
    if(n==0)
        return 1;
    else 
        return n*factorial(n-1);
}

int fib(int n)
{
	if (n == 0 || n ==1)
		return 1;
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

void reverse(string str, int i) {
	if (i - 1 > 0)
            cout << str[i];
        
	reverse(str, i--);
}

int count(int min, int max, int i) {
	if (min != max)
		if (min % 3 == 0)
			i++;
	return count(min++, max, i++);

}

void reversell(nodeType *head) {
	nodeType * ptr = head;        
	if (ptr != NULL){
	reversell(ptr->link);
	cout << ptr->info << " ";}
}

bool  searchll(nodeType *head, int key)
{
	if (head != NULL && head->info == key)
		return true;

	//return searchll(head->link, key);
}

void decToBin(int n, int base){
    if(n>0){
        decToBin(n / base, base);
        cout << n % base<< " ";
    }
}




int main()
{
	cout << "Hello World" << endl;
        cout<<"Please enter the the decimal number to convert followed by its base of conversion: ";
        int numb;
        int base;
        cin >> numb >>base;
        cout<<"CONVERSION---->decToBin of "<< numb <<" is : ";
        decToBin(numb,base);
        
        cout<<"\n================================================================="<<endl;
	nodeType *head, *current;
	head=buildListBackward();
	current = head;
	cout <<"\nList printing backwards is as follow: ";

	while (current->link != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
        cout<< endl;
        cout<<"\n================================================================="<<endl;
        cout <<"using reversell: "; 
        reversell(head);
        
        cout<<"\n================================================================="<<endl;
        int n=0, i=0;
        cout << "\nFIBONACCI SEQUENCE- Input a positive number: ";
        cin >> n;
	cout << "FIB Sequence is as follow: ";
	fib(n);
	while (i < n)
            {
		cout << " " << fib(i);
		i++;
            }
        
        cout<<"\n================================================================="<<endl;
        cout<<"Factorial using recursion :please enter a positive integer:"<<endl;
        int num;
        cin>> num;
        cout<<"Result:"<<factorial(num)<<endl;
          cout<<"================================================================="<<endl;
        cout << "Reversing strings : (skipped) ";
	//string in = "";
	//cin >> in;
	//reverse("elevator", 8);
        
	cout << "Good BYE" <<endl;

	return 0;

}//end Main



