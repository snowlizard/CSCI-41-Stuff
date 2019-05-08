#include <iostream>
#include <iomanip>
#include <string>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;
    
    int a = 4;
    
    tree.binarySearchAdd(a);
    tree.binarySearchAdd(3);
    tree.binarySearchAdd(1);
    tree.binarySearchAdd(2);
    
    tree.binarySearchRemove(4);
    
    tree.displayInorder();
    return 0;
}

