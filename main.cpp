#include <iostream>
#include "SortedList.h"

using namespace std;

int main()
{
    SortedList<int> myList;
    
    myList.insertSorted(4);
    myList.insertSorted(3);
    
    myList.displayList();
    
    int i = myList.getPosition(4);
    
    cout << "pos " << i << endl;
    
    
    
    
    return 0;
}
