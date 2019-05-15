#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree<int> tree;

    int ans = 0;
    int input = 0;
    while ( ans != 4)
    {
        cout << "1. Add to tree\n";
        cout << "2. Remove item\n";
        cout << "3. Display in order\n";
        cout << "4. Exit\n";
        cin >> ans;
        if ( ans == 1 )
        {
            cout << "Enter item you wish to add.\n";
            cin >> input;
            tree.binarySearchAdd(input);
        }
        else if ( ans == 2 )
        {
            cout << "Enter item you wish to remove.\n";
            cin >> input;
            tree.binarySearchRemove(input);
        }
        else if ( ans == 3)
        {
            cout << "----------------------\n";
            tree.displayInorder();
            cout << endl;
            cout << "-----------------------\n";
        }
        else if ( ans == 4 )
        {
            exit(0);
        }
    }
   
    return 0;
}

