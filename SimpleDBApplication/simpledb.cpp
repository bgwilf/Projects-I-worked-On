/* Project:
 * File:   simpleDB.cpp
 * Team Members: Gilles wilfried Bassole & SOUROU K AGBE
 *
 * 
 */

//#include "orderedLinkedList.h"
#include <cstdlib>
#include "orderedList.h"


using namespace std;

int main() {
    
    cout<<"\t\t\t//**********************************************************//" <<endl
        <<"\t\t\t//                                                          //" <<endl
        <<"\t\t\t//                  SIMPLE DATABASE PROJECT                 //" <<endl
        <<"\t\t\t//                                                          //" <<endl
        <<"\t\t\t// @Gilles                                           @SOUROU//" <<endl    
        <<"\t\t\t//**********************************************************//" <<endl;
        
    int choice=0;
    NodeType *first = NULL;
    NodeType *last = NULL;
        
    bool option = true;
   // Present a menu and code the handling of the input.
	while (choice!=10)
	{
		cout<<"\n\t\t\t<------ PROJECT MENU ------>"<<endl;
		if (option)
			cout << "AT THE START OF THE PROGRAM PLEASE SELECT OPTION 1 TO LOAD THE DATABASE" << endl;

			cout<<"\t1. CREATECLASSLIST "<<endl
				<<"\t2. INSERT          "<<endl
				<<"\t3. DELETE          "<<endl
				<<"\t4. SORT            "<<endl
				<<"\t5. SEARCH          "<<endl
				<<"\t6. UPDATE          "<<endl
				<<"\t7. HONOR_STUDENTS  "<<endl
				<<"\t8. WARN_STUDENTS   "<<endl
				<<"\t9. PRINT           "<<endl
				<<"\t10.QUIT            "<<endl<<endl;

			cout<<"\t\t PLease make a selection to: ";
			cin >>choice;
		
		//if input failed
		if (cin.fail())
		{
			cout << "\nPlease select an option between 1 and 10." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (choice != 1 && option == true) //if user does not select option 1 as first option
		{
			if (choice != 10)
				cout << "\nPlease select option 1 before the other options." << endl;
		}
		else
		{
			switch (choice)
			{
				case 1:     // create class list
					cout << "\ncreate class list..." << endl;
					CreateClassList(first, last);
					PrintList(first);
					option = false;
					break;

				case 2:     //INSERT
					cout << "INSERTION...";
                                        Insert(first);
                                        break;

				case 3:     //DELETE
					cout << "DELETION" << endl;
                                        Delete(first);
					break;

				case 4:     //SORT
					cout << "SORT ..." << endl;
					 Sort(first);
                                         break;

				case 5:     //SEARCH
					cout << "SEARCH   " << endl;
					Search(first);
                                        break;

				case 6:     //UPDATE
					cout << "UPDATE LISTING " << endl;
					Update(first);
                                        break;

				case 7:     //HONORSTUDENTS
					cout << " PRINTING LIST OF HONORSTUDENTS..." << endl;
					HonorStudents(first);
                                        break;

				case 8:     //WARNSTUDENTS
					cout << "WARN STUDENTS " << endl;
					WarnStudent(first);
                                        break;

				case 9:     //PRINTING
					cout << " PRINTING LIST" << endl;
					Print(first);
                                        break;

				case 10:  //QUITTING
					cout << "You chose to QUIT!!! ";//quit = true;
					cout << "GOOD BYE!" << endl;
					break;

				default:
					cout << "ERROR: Invalid input...try again !!" << endl;
					cout << "Please select an option between 1 and 10." << endl;
					break;

			}//End Switch
		}// end else

    } // end while loop

	cout <<"Exiting program now..."<<endl;

    return 0;
}

