#include <iostream>
#include <iomanip>
#include "PQueue.h"
#include "PatientRecord.h"

using namespace std;

void showMenu()
{
    cout << "Please select one of the following:\n";
    cout << "+" << setfill('-')<< setw(35)<<"+" <<endl;
    cout << setfill(' ');
    cout <<"|"<< "1. Register a Patient." <<setw(12)<< "|\n";
    cout <<"|" << "2. Display Patient Queue."<<setw(9) <<"|\n";
    cout <<"|"<<"3. Remove a patient from Queue."<<setw(3)<<"|\n";
    cout <<"|"<< "4. Close registration."<<setw(12)<<"|\n";
    cout << "+" << setfill('-')<< setw(35)<<"+" <<endl;
    
}
// not working need to check for invalid input
void getpatientInfo(PQueue<PatientRecord> &pq)
{
    string info;
    int priority;
    PatientRecord temp;
    
    cout << "Enter patient Last name: \n";
    cin >> info;
    temp.setLast(info);
    cout << "Enter patient First name: \n";
    cin >> info;
    temp.setFirst(info);
    cout << "Enter patient date of birth: \n";
    cin >> info;
    temp.setDOB(info);
    cout << "Enter patient symptoms: \n";
    cin >> info;
    temp.setSymptoms(info);
    cout << "Enter patient priority number: \n";
    cin >> priority;
    temp.setPriority(priority);
    pq.enqueue(temp);
    
}

int main()
{
    
    PQueue<PatientRecord> pq;
    
    int action;
    string str;
    bool running = true;
    
    while ( running )
    {
        showMenu();
        cin >> action;
        
        if ( action == 1 )
        {
            getpatientInfo(pq);
        }
        else if ( action == 2)
        {
            pq.displayQueue();
        }
        else if ( action == 3 )
        {
            pq.dequeue();
        }
        else if ( action == 4 ){
            cout << "Closing registration!\n";
            running = false;
        }
        else {
            cout << "ERROR: Invalid Input\n";
        }
    }
    return 0;
}

/**
 int action;
 menu();
 
 cin >> action;
 
 while ( action != 4)
 {
 if ( action == 4 )
 {
 cout << "Closing Registration!\n";
 exit(0);
 }
 if ( action == 2 )
 {
 cout << "2\n";
 }
 else {
 cout << "ERROR: Invalid Input\n";
 }
 menu();
 cin >> action;
 }
 **/
