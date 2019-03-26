#include<iostream>
#include"Node.h"
#include"SortedList.h"
#include "Queue.h"
#include "DataElement.h"
#include "Event.h"
#include<ctime>

using namespace std;
int main()
{
    SortedList<int> aList;
    //Test inserSorted() funciton
    srand(static_cast<unsigned int>(time(NULL)));
    for(int i=0;i<8;i++){
        aList.insertSorted(rand()%100);
    }
    cout<<"================\n";
    aList.displayList();
    cout<<"================\n";
    //Test clear() function
    aList.clear();
    aList.insertSorted(17);
    aList.insertSorted(5);
    aList.insertSorted(21);
    aList.insertSorted(15);
    aList.insertSorted(4);
    cout<<"================\n";
    aList.displayList();
    cout<<"================\n";
    //Test removeSorted() function
    if(!aList.removeSorted(20)){
        cout<<"Removal failed!\n";
    }
    if(!aList.removeSorted(15)){
        cout<<"Removal failed!\n";
    }
    cout<<"================\n";
    aList.displayList();
    cout<<"================\n";
    if(!aList.removeSorted(4)){
        cout<<"Removal failed!\n";
    }
    if(!aList.removeSorted(21)){
        cout<<"Removal failed!\n";
    }
    cout<<"================\n";
    aList.displayList();
    cout<<"================\n";
    //Test getPosition() function
    cout<<"The postion of 25 is "<<aList.getPosition(25)<<endl;
    cout<<"The postion of 2 is "<<aList.getPosition(2)<<endl;
    cout<<"The postion of 11 is "<<aList.getPosition(11)<<endl;
    return 0;
}

