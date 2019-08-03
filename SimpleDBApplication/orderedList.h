#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

/* Project:
* File:   orderedList.cpp
* Team Members: Gilles wilfried Bassole & SOUROU K AGBE
*
*
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Student
{
    string fName;
    string lName;
    int id;
    double gpa;
    string phone;
};

struct NodeType
{
    Student data;
    NodeType *next;
    NodeType *prev;
};

void PrintList(NodeType *first)     //Function to print student information in alphabetically ordered, by last name
{
    NodeType *temp = first;

    while(temp != NULL)     //loop will run until temp pointer reached last node of linked list
    {
        cout << setw(12) <<temp->data.fName << setw(12) << temp->data.lName << setw(12) << temp->data.id << setw(12);
        cout << std::fixed <<setprecision(1) << temp->data.gpa << setw(20) <<temp->data.phone << endl;
        temp = temp->next;
    }
}

void SortbylName (NodeType* &first)    //uses insertion sort to sort the student list by last name
{
   NodeType *temp= first;
   NodeType* check=first->next;
   NodeType* holder=temp;

    while (temp->next !=NULL)
        {
        while (check !=NULL)
            {

            if ((check->data.lName < temp->data.lName) || (check->data.lName == temp->data.lName && check->data.fName < temp->data.fName))
                {
                holder= new NodeType;
                holder->data = temp->data;
                temp->data=check->data;
                check->data=holder->data;
                }
            check= check->next;
            }
        temp=temp->next;
        check=temp->next;
        }
}

void DeleteList(NodeType* &first, NodeType* &last)
{
    if(first != NULL)
    {
        NodeType *temp = first;
        while(first->next != NULL)
        {
            first=first->next;
            delete temp;
            temp = first;
        }
        delete first;
        first=NULL;
        last = NULL;
        temp=NULL;
    }
}

void CreateClassList(NodeType* &first, NodeType* &last)    // Function to load all information in the linked list
{
    ifstream input("COSC666.txt");                            // Reading from file COSC333.txt
    //make sure list is empty before inserting the values
    DeleteList(first, last);

    //get data for first node

    first = new NodeType;
    input >> first->data.fName >> first->data.lName >> first->data.id >> first->data.gpa;  // Reading from file
    string number = "";
    string str_temp;
    input >> str_temp;
    number = str_temp + " ";
    input >> str_temp;
    number = number + str_temp + " ";
    input >> str_temp;
    number = number + str_temp;                        // combine space separated strings to read whole number
    first->data.phone = number;
    last = first;
    first->prev = NULL;
    first->next = NULL;

    NodeType *temp;
    NodeType *previous = first;

    while(!input.eof())
    {
        temp = new NodeType;
        temp->next = NULL;
        previous->next = temp;
        temp->prev = previous;

        input >> temp->data.fName >> temp->data.lName >> temp->data.id >> temp->data.gpa;
        number = "";
        input >> str_temp;
        number = str_temp + " ";
        input >> str_temp;
        number = number + str_temp + " ";
        input >> str_temp;
        number = number + str_temp;
        temp->data.phone = number;
        previous = temp;
    }
    SortbylName(first);

    input.close();
}



void SortbyfName(NodeType* &first)                            // Function to sort list by first name
{
    NodeType *temp= first;
   NodeType* check=first->next;
   NodeType* holder=temp;


    while (temp->next !=NULL)                                 // Terminating condition for the loop
        {
        while (check !=NULL)
            {

            if (check->data.fName < temp->data.fName)        // condition to check if the information is alphabetic order, by first name
                {
                holder= new NodeType;
                holder->data = temp->data;
                temp->data=check->data;
                check->data=holder->data;
                }
            check= check->next;
            }
        temp=temp->next;
        check=temp->next;
        }

}

void SortbyGPA(NodeType* &first)                             // Function to sort information by gpa
{
   NodeType *temp= first;
   NodeType* check=first->next;
   NodeType* holder=temp;


    while (temp->next !=NULL)
        {
        while (check !=NULL)
            {

            if (check->data.gpa > temp->data.gpa)
                {
                holder= new NodeType;
                holder->data = temp->data;
                temp->data=check->data;
                check->data=holder->data;
                }
            check= check->next;
            }
        temp=temp->next;
        check=temp->next;
        }

}

void SortbyID(NodeType* &first)                                    // Function to sort information by ID
{
   NodeType *temp= first;
   NodeType* check=first->next;
   NodeType* holder=temp;


    while (temp->next !=NULL)
        {
        while (check !=NULL)
            {

            if (check->data.id < temp->data.id)
                {
                holder= new NodeType;
                holder->data = temp->data;
                temp->data=check->data;
                check->data=holder->data;
                }
            check= check->next;
            }
        temp=temp->next;
        check=temp->next;
        }

}
//helper function that will return true if there are no non-alphabetic characters in the input string and false otherwise
bool nameValid(string name)
{
    for(int i = 0; i < name.length(); i++)
    {
        if(isalpha(name[i]) == false)
            return false;
    }
    return true;
}

//helper function that will capitalize the first letter of a string if it is not already capital
string firstUpper(string name)
{
    if(name[0] >= 97 && name[0] <= 122)
    {
        name[0] = name[0] - 32;
    }

    return name;
}

void Insert (NodeType* &first)    // Function to insert information in the list
{
    int count=0;
    NodeType* New_entry = new NodeType;
    cout << "Enter the first name" <<endl;
    cin >> New_entry->data.fName;

    bool firstNameValid = nameValid(New_entry->data.fName); //will check if the entered first name is valid
    if(firstNameValid == false)
    {
        while(firstNameValid == false)
        {
            cout << "First name contains invalid characters. Please re-enter first name." << endl;
            cin >> New_entry->data.fName;
            firstNameValid = nameValid(New_entry->data.fName);
        }
    }
    New_entry->data.fName = firstUpper(New_entry->data.fName);
    cout << "Enter the last name"<<endl;
    cin >> New_entry->data.lName;
    bool lastNameValid = nameValid(New_entry->data.lName); //will check if the entered last name is valid
    if(lastNameValid == false)
    {
        while(lastNameValid == false)
        {
            cout << "Last name contains invalid characters. Please re-enter last name." << endl;
            cin >> New_entry->data.lName;
            lastNameValid = nameValid(New_entry->data.lName);
        }
    }
    New_entry->data.lName = firstUpper(New_entry->data.lName);

    cout << "Enter ID"<<endl;
    cin >> New_entry->data.id;
    cout << "Enter GPA"<<endl;
    cin >> New_entry->data.gpa;
    cout << "Enter phone number"<<endl;
    getchar();
    //use getline instead of cin to read any spaces in the phone number
    getline(cin,New_entry->data.phone);

    //insert new node in the proper location
    NodeType* temp= first;
    NodeType* check=first->next;
    if(New_entry->data.lName < temp->data.lName) //insert at first node
    {
       first = New_entry;
       New_entry->next = temp;
    }
    else //insert at non-first node
    {
        while(New_entry->data.lName > check->data.lName )
        {
          //bring temp and check behind and in front of new node, respectively
          temp = temp->next;
          check = check->next;
          if(check == NULL)
            break;
        }
        //insert new node into proper location
        temp->next = New_entry;
        New_entry->next = check;
    }

    //count the number of nodes
    temp= first;
    while(temp != NULL)
    {
        temp=temp->next;
        count++;
    }
    cout << "Number of students in the class is: " << count << endl;
    SortbylName(first);
    PrintList(first);


}

void Delete (NodeType* &first)                            // Function to delete record from the list
{
     string f_name,l_name;
     int option,count=0;
     bool found = false;
     NodeType *temp1= first;
     cout << "Enter the option of your choice"<<endl;
     cout << "(1) Delete by name" << endl;
     cout << "(2) Delete by ID" << endl;
     cin >> option;
     switch (option)
     {
     case(1):{
         cout << "Enter first name"<<endl; //Deleting by name
         cin >> f_name;
         bool firstNameValid = nameValid(f_name);

         if(firstNameValid == false)
         {
             while(firstNameValid == false)
             {
                 cout << "First name contains invalid characters. Please re-enter first name." << endl;
                 cin >> f_name;
                 firstNameValid = nameValid(f_name);
             }
         }
         f_name = firstUpper(f_name);
         cout << "Enter last name"<<endl;
         cin >> l_name;

         bool lastNameValid = nameValid(l_name);

         if(lastNameValid == false)
         {
             while(lastNameValid == false)
             {
                 cout << "Last name contains invalid characters. Please re-enter last name." << endl;
                 cin >> l_name;
                 lastNameValid = nameValid(l_name);
             }
         }
         l_name = firstUpper(l_name);
         NodeType *temp= first;
         NodeType* check=first->next;

         //check if record to delete is in the beginning
         if((temp->data.fName).compare(f_name)==0 && ((temp->data.lName).compare(l_name)) == 0)   //Deleting the record from first node and pointing head to the next pointer
            {
                first = check;
                delete temp;
                found = true;
            }
         else{ //check if record to delete is in the middle or end of the list
                while(check!=NULL)
                {
                    if((check->data.fName).compare(f_name)==0 && ((check->data.lName).compare(l_name)) == 0)
                      {
                        temp->next = check->next;
                        delete check;
                        found = true;
                        break;
                      }
                    else
                      {
                        temp=temp->next;
                        check=check->next;
                      }
                }
         }
        break;}
     case(2):
         {
         cout << "Enter student ID: " << endl;                             // Delete by student Id
         int s_id;
         cin >> s_id;
         NodeType *temp= first;
         NodeType* check=first->next;
         if(temp->data.id == s_id)
         {
             first = check;
             delete temp;
             found = true;
         }
         else{
            while(check!= NULL )
            {
                if((check->data.id) == (s_id))
                {
                    temp->next= check->next;
                    delete check;
                    found = true;
                    break;
                }
                else{
                    temp=temp->next;
                    check = check->next;
                }
            }

         }

        break;}
     default:
         cout << "Invalid Selection !!"<< endl;
        break;
     }
     //if record was found and deleted print Record delete, otherwise Student is not registered
     if(found== true)
     cout << "Record deleted" << endl;
     else if(found == false)
     cout << "Student is not registered !!" << endl;
     temp1= first;
     while(temp1 !=NULL)
     {
         temp1=temp1->next;
         count++;

     }
        cout << "Number of students in the class is: " << count << endl;
        PrintList(first);
}

void Search (NodeType* &first)                                                   //Function to search a record
{
   bool found = false;
   int student_id;
   cout << "Enter student ID" << endl;
   cin >> student_id;
   NodeType *temp= first;
   while(temp != NULL)
   {
       if(temp->data.id==student_id)                                             //After getting the record,print the same
       {   found = true;
           cout << "First Name: " << temp->data.fName<<endl;
           cout << "Last Name: " << temp->data.lName<<endl;
           cout << "ID: " << temp->data.id << endl;
           cout << "GPA: " << temp->data.gpa << endl;
           cout << "Phone: " << temp->data.phone << endl;
           break;

       }
       else
       temp=temp->next;
   }
    if(found==false)
        cout << "Student is not registered !!" << endl;

}


void Update (NodeType* &first)                                            // Function to update record
{   cout << "Enter student ID: ";
    int student_id;
    cin >> student_id;
    bool found = false;
    NodeType *check= first;
    while(check!= NULL)
    {
        if(check->data.id == student_id)
        {
            found = true;
            break;
        }
        else
            check = check->next;
    }
    if(found==true){
        cout<< "Choose your option:"<< endl;
        cout << "(1)Update GPA"<<endl;
        cout << "(2)Update phone number"<< endl;
        cout << "(3)Update both"<< endl;
        int update_selection;
        cin >> update_selection;
         NodeType *temp= first;
       while(temp->next != NULL)
       {
           if(temp->data.id==student_id)
              break;
           else
           temp=temp->next;
       }
       double nGPA=0;
       string phone_no="";

        switch(update_selection)
        {
            case(1):
                cout << "Enter new GPA" << endl;
                cin >> nGPA;
                temp->data.gpa = nGPA;
                break;
            case(2):
                cout << "Update phone number"<<endl;
                cin >> phone_no;
                temp->data.phone = phone_no;
                break;
            case(3):
                cout << "Enter new GPA" << endl;
                cin >> nGPA;
                temp->data.gpa = nGPA;
                cout << "Update phone number" << endl;
                cin >> phone_no;
                temp->data.phone = phone_no;
                break;
            default:
                cout << "Invalid selection" <<endl;
                break;
        }
        cout << "Updated student's information" << endl;
        cout << "Student ID: " << student_id <<endl;
        if(nGPA!=0)
            cout << "New GPA: " << nGPA;
        if(phone_no.compare("")!=0)
            cout << "New Phone no: "<<phone_no<<endl;
    }
    else
        cout << "Student is not registered";
}

void HonorStudents(NodeType* &first)      //Function to list all those students whose GPA is greater than 3.6
{
    NodeType *temp= first;
    int count =0;
    cout << "\nFollowing is the list of students whose GPA is greater than 3.6"<< endl;
    while(temp != NULL)
    {
       if(temp->data.gpa > 3.6)
       {
           cout <<(count+1)<<". "<<temp->data.fName << " " << temp->data.lName << endl;
           count = count+1;
       }
       temp=temp->next;
    }
   cout << "Number of such students is : " << count << endl;
}

void WarnStudent(NodeType* &first)      //Function to list all those students whose GPA is less than 2.0
{
    NodeType *temp= first;
    int count =0;
    cout << "\nFollowing is the list of students whose GPA is less than 2.0"<< endl;
    while(temp->next != NULL)
    {
       if(temp->data.gpa < 2.0)
       {
           cout <<(count+1)<<". "<<temp->data.fName << " " << temp->data.lName << endl;
           count = count+1;
       }
       temp=temp->next;
    }
    cout << "Number of such students is : " << count << endl;

}



void Sort(NodeType* &first)                                              // Sort according to first name,GPA or student ID depending upon user input
{   int sort_option;
    cout << "Choose your option: " << endl;
    cout << "(1) Sort by first name" << endl;
    cout << "(2) Sort by GPA" << endl;
    cout << "(3) Sort by ID" << endl;
    cin >> sort_option;
    switch(sort_option)
    {
    case(1):
        SortbyfName(first);
        PrintList(first);
        break;
    case(2):
        SortbyGPA(first);
        PrintList(first);
        break;
    case(3):
        SortbyID(first);
        PrintList(first);
        break;
    default:
        cout << "Invalid Selection !!" << endl;
        break;
    }
}

void Print(NodeType* &first)
{
    SortbylName(first);
    PrintList(first);
    int count =0;
    NodeType *temp1= first;
    while(temp1!=NULL)
 {
     temp1=temp1->next;
     count++;
 }
    cout << "Number of students in the class is: " << count << endl;

}
/*
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Student
{
	string fName;
	string lName;
	int id;
	double gpa;
	string phone;
};

struct nodeType
{
	Student data;
	nodeType *next;
	nodeType *prev;
};

//Gilles
void CreateClassList(nodeType* &first, nodeType* &last)    // Function to load all information in the linked list
{
	ifstream input("COSC666.txt");                            // Reading from file COSC333.txt
															  //make sure list is empty before inserting the values
	DeleteList(first, last);

	//get data for first node

	first = new nodeType;
	input >> first->data.fName >> first->data.lName >> first->data.id >> first->data.gpa;  // Reading from file
	string number = "";
	string str_temp;
	input >> str_temp;
	number = str_temp + " ";
	input >> str_temp;
	number = number + str_temp + " ";
	input >> str_temp;
	number = number + str_temp;                        // combine space separated strings to read whole number
	first->data.phone = number;
	last = first;
	first->prev = NULL;
	first->next = NULL;

	nodeType *temp;
	nodeType *previous = first;

	while (!input.eof())
	{
		temp = new nodeType;
		temp->next = NULL;
		previous->next = temp;
		temp->prev = previous;

		input >> temp->data.fName >> temp->data.lName >> temp->data.id >> temp->data.gpa;
		number = "";
		input >> str_temp;
		number = str_temp + " ";
		input >> str_temp;
		number = number + str_temp + " ";
		input >> str_temp;
		number = number + str_temp;
		temp->data.phone = number;
		previous = temp;
	}
	SortbylName(first);

	input.close();
}
//Gilles
void Print(nodeType* &first)
{
	SortbylName(first);
	PrintList(first);
	int count = 0;
	nodeType *temp1 = first;
	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		count++;
	}
	cout << "Number of students in the class is: " << count << endl;

}
//Gilles
void PrintList(nodeType *first)     //Function to print student information in alphabetically ordered, by last name
{
	nodeType *temp = first;

	while (temp != NULL)     //loop will run until temp pointer reached last node of linked list
	{
		cout << setw(12) << temp->data.fName << setw(12) << temp->data.lName << setw(12) << temp->data.id << setw(12);
		cout << std::fixed << setprecision(1) << temp->data.gpa << setw(20) << temp->data.phone << endl;
		temp = temp->next;
	}
}
//Gilles
void Insert(nodeType* &first)    // Function to insert information in the list
{
	int count = 0;
	nodeType* New_entry = new nodeType;
	cout << "Enter the first name" << endl;
	cin >> New_entry->data.fName;

	bool firstNameValid = nameValid(New_entry->data.fName); //will check if the entered first name is valid
	if (firstNameValid == false)
	{
		while (firstNameValid == false)
		{
			cout << "First name contains invalid characters. Please re-enter first name." << endl;
			cin >> New_entry->data.fName;
			firstNameValid = nameValid(New_entry->data.fName);
		}
	}
	New_entry->data.fName = firstUpper(New_entry->data.fName);
	cout << "Enter the last name" << endl;
	cin >> New_entry->data.lName;
	bool lastNameValid = nameValid(New_entry->data.lName); //will check if the entered last name is valid
	if (lastNameValid == false)
	{
		while (lastNameValid == false)
		{
			cout << "Last name contains invalid characters. Please re-enter last name." << endl;
			cin >> New_entry->data.lName;
			lastNameValid = nameValid(New_entry->data.lName);
		}
	}
	New_entry->data.lName = firstUpper(New_entry->data.lName);

	cout << "Enter ID" << endl;
	cin >> New_entry->data.id;
	cout << "Enter GPA" << endl;
	cin >> New_entry->data.gpa;
	cout << "Enter phone number" << endl;
	getchar();
	//use getline instead of cin to read any spaces in the phone number
	getline(cin, New_entry->data.phone);

	//insert new node in the proper location
	nodeType* temp = first;
	nodeType* check = first->next;
	if (New_entry->data.lName < temp->data.lName) //insert at first node
	{
		first = New_entry;
		New_entry->next = temp;
	}
	else //insert at non-first node
	{
		while (New_entry->data.lName > check->data.lName)
		{
			//bring temp and check behind and in front of new node, respectively
			temp = temp->next;
			check = check->next;
			if (check == NULL)
				break;
		}
		//insert new node into proper location
		temp->next = New_entry;
		New_entry->next = check;
	}

	//count the number of nodes
	temp = first;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	cout << "Number of students in the class is: " << count << endl;
	SortbylName(first);
	PrintList(first);


}
//Gilles
void Update(nodeType* &first)                                            // Function to update record
{
	cout << "Enter student ID: ";
	int student_id;
	cin >> student_id;
	bool found = false;
	nodeType *check = first;
	while (check != NULL)
	{
		if (check->data.id == student_id)
		{
			found = true;
			break;
		}
		else
			check = check->next;
	}
	if (found == true) {
		cout << "Choose your option:" << endl;
		cout << "(1)Update GPA" << endl;
		cout << "(2)Update phone number" << endl;
		cout << "(3)Update both" << endl;
		int update_selection;
		cin >> update_selection;
		nodeType *temp = first;
		while (temp->next != NULL)
		{
			if (temp->data.id == student_id)
				break;
			else
				temp = temp->next;
		}
		double nGPA = 0;
		string phone_no = "";

		switch (update_selection)
		{
		case(1):
			cout << "Enter new GPA" << endl;
			cin >> nGPA;
			temp->data.gpa = nGPA;
			break;
		case(2):
			cout << "Update phone number" << endl;
			cin >> phone_no;
			temp->data.phone = phone_no;
			break;
		case(3):
			cout << "Enter new GPA" << endl;
			cin >> nGPA;
			temp->data.gpa = nGPA;
			cout << "Update phone number" << endl;
			cin >> phone_no;
			temp->data.phone = phone_no;
			break;
		default:
			cout << "Invalid selection" << endl;
			break;
		}
		cout << "Updated student's information" << endl;
		cout << "Student ID: " << student_id << endl;
		if (nGPA != 0)
			cout << "New GPA: " << nGPA;
		if (phone_no.compare("") != 0)
			cout << "New Phone no: " << phone_no << endl;
	}
	else
		cout << "Student is not registered";
}
//Gilles
void Sort(nodeType* &first)                                              // Sort according to first name,GPA or student ID depending upon user input
{
	int sort_option;
	cout << "Choose your option: " << endl;
	cout << "(1) Sort by first name" << endl;
	cout << "(2) Sort by GPA" << endl;
	cout << "(3) Sort by ID" << endl;
	cin >> sort_option;
	switch (sort_option)
	{
	case(1):
		SortbyfName(first);
		PrintList(first);
		break;
	case(2):
		SortbyGPA(first);
		PrintList(first);
		break;
	case(3):
		SortbyID(first);
		PrintList(first);
		break;
	default:
		cout << "Invalid Selection !!" << endl;
		break;
	}
}
//Gilles
void SortbylName(nodeType* &first)    //uses insertion sort to sort the student list by last name
{
	nodeType *temp = first;
	nodeType *check = first->next;
	nodeType *holder = temp;

	while (temp->next != NULL)
	{
		while (check != NULL)
		{

			if ((check->data.lName < temp->data.lName) || (check->data.lName == temp->data.lName && check->data.fName < temp->data.fName))
			{
				holder = new nodeType;
				holder->data = temp->data;
				temp->data = check->data;
				check->data = holder->data;
			}
			check = check->next;
		}
		temp = temp->next;
		check = temp->next;
	}
}
void SortbyfName(nodeType* &first)                            // Function to sort list by first name
{
	nodeType *temp = first;
	nodeType* check = first->next;
	nodeType* holder = temp;


	while (temp->next != NULL)                                 // Terminating condition for the loop
	{
		while (check != NULL)
		{

			if (check->data.fName < temp->data.fName)        // condition to check if the information is alphabetic order, by first name
			{
				holder = new nodeType;
				holder->data = temp->data;
				temp->data = check->data;
				check->data = holder->data;
			}
			check = check->next;
		}
		temp = temp->next;
		check = temp->next;
	}

}
void SortbyGPA(nodeType* &first)                             // Function to sort information by gpa
{
	nodeType *temp = first;
	nodeType* check = first->next;
	nodeType* holder = temp;


	while (temp->next != NULL)
	{
		while (check != NULL)
		{

			if (check->data.gpa > temp->data.gpa)
			{
				holder = new nodeType;
				holder->data = temp->data;
				temp->data = check->data;
				check->data = holder->data;
			}
			check = check->next;
		}
		temp = temp->next;
		check = temp->next;
	}

}
void SortbyID(nodeType* &first)                                    // Function to sort information by ID
{
	nodeType *temp = first;
	nodeType* check = first->next;
	nodeType* holder = temp;


	while (temp->next != NULL)
	{
		while (check != NULL)
		{

			if (check->data.id < temp->data.id)
			{
				holder = new nodeType;
				holder->data = temp->data;
				temp->data = check->data;
				check->data = holder->data;
			}
			check = check->next;
		}
		temp = temp->next;
		check = temp->next;
	}

}
//helper function that will return true if there are no non-alphabetic characters in the input string and false otherwise
bool nameValid(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (isalpha(name[i]) == false)
			return false;
	}
	return true;
}
//helper function that will capitalize the first letter of a string if it is not already capital
string firstUpper(string name)
{
	if (name[0] >= 97 && name[0] <= 122)
	{
		name[0] = name[0] - 32;
	}

	return name;
}


//SOUROU
void Search(nodeType* &first)                                                   //Function to search a record
{
	bool found = false;
	int student_id;
	cout << "Enter student ID" << endl;
	cin >> student_id;
	nodeType *temp = first;
	while (temp != NULL)
	{
		if (temp->data.id == student_id)                                             //After getting the record,print the same
		{
			found = true;
			cout << "First Name: " << temp->data.fName << endl;
			cout << "Last Name: " << temp->data.lName << endl;
			cout << "ID: " << temp->data.id << endl;
			cout << "GPA: " << temp->data.gpa << endl;
			cout << "Phone: " << temp->data.phone << endl;
			break;

		}
		else
			temp = temp->next;
	}
	if (found == false)
		cout << "Student is not registered !!" << endl;

}
//SOUROU
void HonorStudents(nodeType* &first)      //Function to list all those students whose GPA is greater than 3.6
{
	nodeType *temp = first;
	int count = 0;
	cout << "\nFollowing is the list of students whose GPA is greater than 3.6" << endl;
	while (temp != NULL)
	{
		if (temp->data.gpa > 3.6)
		{
			cout << (count + 1) << ". " << temp->data.fName << " " << temp->data.lName << endl;
			count = count + 1;
		}
		temp = temp->next;
	}
	cout << "Number of such students is : " << count << endl;
}
//SOUROU
void WarnStudent(nodeType* &first)      //Function to list all those students whose GPA is less than 2.0
{
	nodeType *temp = first;
	int count = 0;
	cout << "\nFollowing is the list of students whose GPA is less than 2.0" << endl;
	while (temp->next != NULL)
	{
		if (temp->data.gpa < 2.0)
		{
			cout << (count + 1) << ". " << temp->data.fName << " " << temp->data.lName << endl;
			count = count + 1;
		}
		temp = temp->next;
	}
	cout << "Number of such students is : " << count << endl;

}
//SOUROU
void Delete(nodeType* &first)                            // Function to delete record from the list
{
	string f_name, l_name;
	int option, count = 0;
	bool found = false;
	nodeType *temp1 = first;
	cout << "Enter the option of your choice" << endl;
	cout << "(1) Delete by name" << endl;
	cout << "(2) Delete by ID" << endl;
	cin >> option;
	switch (option)
	{
	case(1): {
		cout << "Enter first name" << endl; //Deleting by name
		cin >> f_name;
		bool firstNameValid = nameValid(f_name);

		if (firstNameValid == false)
		{
			while (firstNameValid == false)
			{
				cout << "First name contains invalid characters. Please re-enter first name." << endl;
				cin >> f_name;
				firstNameValid = nameValid(f_name);
			}
		}
		f_name = firstUpper(f_name);
		cout << "Enter last name" << endl;
		cin >> l_name;

		bool lastNameValid = nameValid(l_name);

		if (lastNameValid == false)
		{
			while (lastNameValid == false)
			{
				cout << "Last name contains invalid characters. Please re-enter last name." << endl;
				cin >> l_name;
				lastNameValid = nameValid(l_name);
			}
		}
		l_name = firstUpper(l_name);
		nodeType *temp = first;
		nodeType* check = first->next;

		//check if record to delete is in the beginning
		if ((temp->data.fName).compare(f_name) == 0 && ((temp->data.lName).compare(l_name)) == 0)   //Deleting the record from first node and pointing head to the next pointer
		{
			first = check;
			delete temp;
			found = true;
		}
		else { //check if record to delete is in the middle or end of the list
			while (check != NULL)
			{
				if ((check->data.fName).compare(f_name) == 0 && ((check->data.lName).compare(l_name)) == 0)
				{
					temp->next = check->next;
					delete check;
					found = true;
					break;
				}
				else
				{
					temp = temp->next;
					check = check->next;
				}
			}
		}
		break; }
	case(2):
	{
		cout << "Enter student ID: " << endl;                             // Delete by student Id
		int s_id;
		cin >> s_id;
		nodeType *temp = first;
		nodeType* check = first->next;
		if (temp->data.id == s_id)
		{
			first = check;
			delete temp;
			found = true;
		}
		else {
			while (check != NULL)
			{
				if ((check->data.id) == (s_id))
				{
					temp->next = check->next;
					delete check;
					found = true;
					break;
				}
				else {
					temp = temp->next;
					check = check->next;
				}
			}

		}

		break; }
	default:
		cout << "Invalid Selection !!" << endl;
		break;
	}
	//if record was found and deleted print Record delete, otherwise Student is not registered
	if (found == true)
		cout << "Record deleted" << endl;
	else if (found == false)
		cout << "Student is not registered !!" << endl;
	temp1 = first;
	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		count++;

	}
	cout << "Number of students in the class is: " << count << endl;
	PrintList(first);
}
//SOUROU
void DeleteList(nodeType* &first, nodeType* &last)
{
	if (first != NULL)
	{
		nodeType *temp = first;
		while (first->next != NULL)
		{
			first = first->next;
			delete temp;
			temp = first;
		}
		delete first;
		first = NULL;
		last = NULL;
		temp = NULL;
	}
}
*/

#endif /* ORDEREDLIST_H */

