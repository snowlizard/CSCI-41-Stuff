#include <iostream>
#include <iomanip>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> aTree;
    aTree.createBinaryTree();
    cout<<"-----------------"<<endl;
    aTree.displayPreorder();
   /**
    cout<<"The number of node in the tree: "<<aTree.getNumberOfNodes()<<endl;
    cout<<"-----------------"<<endl;
    aTree.addNewItem(11);
    aTree.displayPreorder();
    cout<<"The number of node in the tree: "<<aTree.getNumberOfNodes()<<endl;
    cout<<"-----------------"<<endl;
    if( !aTree.isEmpty() ){
        cout<<"The sume of the items in the tree is "<<aTree.getSum()<<endl;
    }
    if( !aTree.isEmpty() ){
        cout<<"The max items in the tree is "<<aTree.getMax()<<endl;
    }
    **/
    cout << "SUM: " << aTree.getSum() << endl;
    return 0;
}

