#include <iostream>
#include <iomanip>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> tree(100);
    
    tree.creatBinaryTree();
    tree.displayPreorder();
    cout << endl;
    tree.displayInorder();
    cout << endl;
    tree.displayPostorder();
    return 0;
}

