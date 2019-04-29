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
public:
    //Constructors
    BinaryTree();
    BinaryTree(const ItemType &rootItem);
    //Set and Get functions
    ItemType getRootItem();
    void setRootItem(const ItemType &rootItem);
    //Other member functions
    bool isEmpty() const;
    void creatBinaryTree();
    void displayPreorder();
    void displayInorder();
    void displayPostorder();
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
void BinaryTree<ItemType>::creatBinaryTree()
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
#endif

