#include <iostream>
#include <iomanip>
#include "PQueue.h"
#include "PatientRecord.h"
#include "BinaryTree.h"

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
void getpatientInfo(PQueue<PatientRecord> &pq)
{
    string info;
    int priority;
    PatientRecord temp;
    
    cout << "Enter patient Last name: \n";
    getline(cin, info);
    temp.setLast(info);
    cout << "Enter patient First name: \n";
    getline(cin,info);
    temp.setFirst(info);
    cout << "Enter patient date of birth: \n";
    getline(cin,info);
    temp.setDOB(info);
    cout << "Enter patient symptoms: \n";
    getline(cin, info);
    temp.setSymptoms(info);
    cout << "Enter patient priority number: \n";
    getline(cin, info);
    priority = stoi(info);
    temp.setPriority(priority);
    pq.enqueue(temp);
    
}

int main()
{
    
    PQueue<PatientRecord> pq;
    
    string str;
    bool running = true;
    
    while ( running )
    {
        showMenu();
        getline(cin, str);
        
        if ( str == "1" )
        {
            getpatientInfo(pq);
        }
        else if ( str == "2")
        {
            pq.displayQueue();
        }
        else if ( str == "3" )
        {
            pq.dequeue();
        }
        else if ( str == "4" ){
            cout << "Closing registration!\n";
            running = false;
            exit(0);
        }
        else {
            cout << "ERROR: Invalid Input\n";
        }
    }
    return 0;
}

