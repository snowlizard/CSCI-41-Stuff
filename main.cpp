#include <iostream>
#include "SortedList.h"

using namespace std;

int main()
{
    SortedList<int> myList;
    
    myList.insertSorted(21);
    myList.insertSorted(3);
    myList.insertSorted(30);
    myList.insertSorted(51);
    
    // remove sorted not removed last node in list correcty or at all
    // instead removees the first node
    myList.removeSorted(51);
    
    //cout << myList.getPosition(30) << "pos\n";
    
    myList.displayList();
    
    
    
    
    
    return 0;
}
