//class template BinaryTree header file: BinaryTree.h
#ifndef _BINARY_TREE
#define _BINARY_TREE
#include <string>
#include <iomanip>
#include"BinaryNode.h"

using namespace std;

template<class ItemType>
class BinaryTree
{
private:
    BinaryNode<ItemType> *rootPtr;
protected:
    void binaryTreeBuilder(BinaryNode<ItemType> *aParent);
    void preOrderVisit(BinaryNode<ItemType> *treeRoot);
    void inOrderVisit(BinaryNode<ItemType> *treeRoot);
    void postOrderVisit(BinaryNode<ItemType> *treeRoot);
    // Assignment 16
    BinaryNode<ItemType> *addNewItemHelper(BinaryNode<ItemType> *treeRoot,ItemType anItem);
    ItemType getSumHelper(BinaryNode<ItemType> *treeRoot);
    int getNumberOfNodesHelper(BinaryNode<ItemType> *treeRoot);
    ItemType getMaxHelper(BinaryNode<ItemType> *treeRoot);
public:
    //Constructors
    BinaryTree();
    BinaryTree(const ItemType &rootItem);
    //Set and Get functions
    ItemType getRootItem();
    void setRootItem(const ItemType &rootItem);
    //Other member functions
    bool isEmpty() const;
    void createBinaryTree();
    void displayPreorder();
    void displayInorder();
    void displayPostorder();
    // Assignment 16
    void addNewItem(ItemType anItem);
    ItemType getSum();
    int getNumberOfNodes();
    ItemType getMax();
};
//Constructors
template<class ItemType>
BinaryTree<ItemType>::BinaryTree()
{
    rootPtr = NULL;
}
template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType &rootItem)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
//Set and Get functions
template<class ItemType>
ItemType BinaryTree<ItemType>::getRootItem()
{
    if (rootPtr != NULL)
        return rootPtr->getItem();
    else {
        cout << "Empty tree!\n";
        exit(1);
    }
}
template<class ItemType>
void BinaryTree<ItemType>::setRootItem(const ItemType &rootItem)
{
    if (rootPtr != NULL)
        rootPtr->setItem(rootItem);
    else
        rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
    return(rootPtr==NULL);
}
//Assignment 15: Please complete following member functions
template<class ItemType>
void BinaryTree<ItemType>::binaryTreeBuilder(BinaryNode<ItemType>
                                             *aParent)
{
    char usrInput;
    ItemType userItem;
    BinaryNode<ItemType> *curNode;
    
    if ( aParent == NULL )
    {
        cout << "Enter data Item you wish to add to tree\n";
        cin >> userItem;
        aParent = new BinaryNode<ItemType>(userItem);
        rootPtr = aParent;
    }
    cout << "Go Left?[Y/N]\n";
    cin >> usrInput;
    cout << "Current Parent " << aParent->getItem() << endl;
    if ( usrInput == 'y' || usrInput == 'Y' )
    {
        cout << "Enter data item you wish to add to left tree.\n";
        cin >> userItem;
        curNode = new BinaryNode<ItemType>(userItem);
        aParent->setLeftChildPtr(curNode);
        binaryTreeBuilder(curNode);
    }
    cout << "Go Right?[Y/N]\n";
    cout << "current parent " << aParent->getItem() << endl;
    cin >> usrInput;
    if ( usrInput == 'y' || usrInput == 'Y' )
    {
        cout << "Enter data item you wish to add to right tree.\n";
        cin >> userItem;
        curNode = new BinaryNode<ItemType>(userItem);
        aParent->setRightChildPtr(curNode);
        binaryTreeBuilder(curNode);
    }
}
template<class ItemType>
void BinaryTree<ItemType>::preOrderVisit(BinaryNode<ItemType> *treeRoot)
{
    if ( treeRoot != NULL )
    {
        cout << treeRoot->getItem() << "\t";
        preOrderVisit(treeRoot->getLeftChildPtr());
        preOrderVisit(treeRoot->getRightChildPtr());
    }
}
template<class ItemType>
void BinaryTree<ItemType>::inOrderVisit(BinaryNode<ItemType> *treeRoot)
{
  if ( treeRoot != NULL )
  {
      inOrderVisit(treeRoot->getLeftChildPtr());
      cout << treeRoot->getItem() << "\t";
      inOrderVisit(treeRoot->getRightChildPtr());
  }
}
template<class ItemType>
void BinaryTree<ItemType>::postOrderVisit(BinaryNode<ItemType> *treeRoot)
{
    if ( treeRoot != NULL )
    {
        postOrderVisit(treeRoot->getLeftChildPtr());
        postOrderVisit(treeRoot->getRightChildPtr());
        cout << treeRoot->getItem() << "\t";
    }
}
template<class ItemType>
void BinaryTree<ItemType>::createBinaryTree()
{
    binaryTreeBuilder(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayPreorder()
{
    preOrderVisit(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayInorder()
{
    inOrderVisit(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayPostorder()
{
    postOrderVisit(rootPtr);
}
// Assignment 16 =================================
template<class ItemType>
BinaryNode<ItemType> *BinaryTree<ItemType>::addNewItemHelper(BinaryNode<ItemType>
                                        *treeRoot,ItemType anItem)
{
    BinaryNode<ItemType> *curNode = new BinaryNode<ItemType>(anItem);
    if ( treeRoot == NULL )
        rootPtr->setItem(anItem);
    
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getSumHelper(BinaryNode<ItemType> *treeRoot)
{
    ItemType sum = treeRoot->getItem();
    if ( isEmpty() )
    {
        exit(0);
    }
    if( treeRoot->getLeftChildPtr() != NULL )
        sum += getSumHelper(treeRoot->getLeftChildPtr());
    if ( treeRoot->getRightChildPtr() != NULL )
        sum += getSumHelper(treeRoot->getRightChildPtr());
    
    return sum;
    
}
template<class ItemType>
int BinaryTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType> *treeRoot)
{
    if ( isEmpty() )
        return 0;
    else
    {
        return 1 + getNumberOfNodesHelper(treeRoot->getLeftChildPtr()) + getNumberOfNodesHelper(treeRoot->getRightChildPtr());
    }
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getMaxHelper(BinaryNode<ItemType> *treeRoot)
{
    ItemType Max = treeRoot->getItem();
    if ( isEmpty() )
        exit(0);
    if ( treeRoot->getLeftChildPtr() != NULL )
    {
        int left = getMaxHelper(treeRoot->getLeftChildPtr());
        if ( Max < left )
            Max = left;
    }
    if ( treeRoot->getRightChildPtr() != NULL )
    {
        int right = getMaxHelper(treeRoot->getRightChildPtr());
        if ( Max < right )
            Max = right;
    }
    return Max;
}

template<class ItemType>
void BinaryTree<ItemType>::addNewItem(ItemType anItem)
{
    addNewItemHelper(rootPtr, anItem);
}

template<class ItemType>
ItemType BinaryTree<ItemType>::getSum()
{
    return getSumHelper(rootPtr);
}
template<class ItemType>
int BinaryTree<ItemType>::getNumberOfNodes()
{
    return getNumberOfNodesHelper(rootPtr);
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getMax()
{
    return getMaxHelper(rootPtr);
}

#endif

