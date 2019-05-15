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
    
    int getHeightHelper(BinaryNode<ItemType> *treeRoot);
    bool containsHelper(BinaryNode<ItemType> *treeRoot, ItemType anItem);
    bool isFullTreeHelper(BinaryNode<ItemType> *treeRoot);
    BinaryNode<ItemType> *removeLeavesHelper(BinaryNode<ItemType> *treeRoot);

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
    
    bool contains(ItemType anItem);
    int getHeight();
    bool isFullTree();
    void removeLeaves();
    
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
    BinaryNode<ItemType> *curPtr;
    char option;
    cout << "Continue to the left?(y/n)\n";
    cin >> option;
    if (option == 'y') {
        ItemType anItem;
        cout << "Enter the information for the data item:\n";
        cin >> anItem;
        curPtr = new BinaryNode<ItemType>(anItem);
        aParent->setLeftChildPtr(curPtr);
        binaryTreeBuilder(curPtr);
    }
    else
        aParent->setLeftChildPtr(NULL);
    cout << "Continue to the right?(y/n)\n";
    cin >> option;
    if (option == 'y') {
        ItemType anItem;
        cout << "Enter the information for the data item:\n";
        cin >> anItem;
        curPtr = new BinaryNode<ItemType>(anItem);
        aParent->setRightChildPtr(curPtr);
        binaryTreeBuilder(curPtr);
    }
    else
        aParent->setRightChildPtr(NULL);
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
void BinaryTree<ItemType>::createBinaryTree()
{
    ItemType anItem;
    cout << "Enter the data item for the root:\n";
    cin >> anItem;
    rootPtr = new BinaryNode<ItemType>(anItem);
    binaryTreeBuilder(rootPtr);
}

template<class ItemType>
void BinaryTree<ItemType>::displayPreorder()
{
    preOrderVisit(rootPtr);
}

// Assignment 16 =================================
template<class ItemType>
BinaryNode<ItemType> *BinaryTree<ItemType>::addNewItemHelper(BinaryNode<ItemType>
                                        *treeRoot,ItemType anItem)
{
   if ( treeRoot == NULL )
   {
       rootPtr = new BinaryNode<ItemType>(anItem);
   }
    else
    {
        char ans;
        cout << "current parent " << treeRoot->getItem() << endl;
        cout << "Add Item to left? [Y/N]\n";
        cin >> ans;
        if ( ans == 'y' )
        {
            if (treeRoot->getLeftChildPtr() == NULL)
            {
                treeRoot->setLeftChildPtr(new BinaryNode<ItemType>(anItem));
            }
            else
                treeRoot->setLeftChildPtr(addNewItemHelper(treeRoot->getLeftChildPtr(), anItem));
        }
        else
        {
            if (treeRoot->getRightChildPtr() == NULL )
                treeRoot->setRightChildPtr(new BinaryNode<ItemType>(anItem));
            else
                treeRoot->setRightChildPtr(addNewItemHelper(treeRoot->getRightChildPtr(), anItem));
        }
    }
    return treeRoot;
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
    int numberOfNodes = 0;
    if (treeRoot != NULL) {
        numberOfNodes = 1 +
        getNumberOfNodesHelper(treeRoot->getLeftChildPtr()) +
        getNumberOfNodesHelper(treeRoot->getRightChildPtr());
    }
    return numberOfNodes;
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
//Assignment 18 -> Complete following functions:
template<class ItemType>
bool BinaryTree<ItemType>::containsHelper(BinaryNode<ItemType> *treeRoot,
                                          ItemType anItem)
{
}
template<class ItemType>
bool BinaryTree<ItemType>::contains(ItemType anItem)
{
    return(containsHelper(rootPtr, anItem));
}
template<class ItemType>
int BinaryTree<ItemType>::getHeightHelper(BinaryNode<ItemType> *treeRoot)
{
}
template<class ItemType>
int BinaryTree<ItemType>::getHeight()
{
    return getHeightHelper(rootPtr);
}
template<class ItemType>
bool BinaryTree<ItemType>::isFullTreeHelper(BinaryNode<ItemType>
                                            *treeRoot)
{
    
}
template<class ItemType>
bool BinaryTree<ItemType>::isFullTree()
{
    return isFullTreeHelper(rootPtr);
}
template<class ItemType>
BinaryTree<ItemType> *BinaryTree<ItemType>::removeLeavesHelper(BinaryNode<ItemType> *treeRoot)
{
}
template<class ItemType>
void BinaryTree<ItemType>::removeLeaves()
{
    rootPtr=removeLeavesHelpter(rootPtr);
}
#endif

