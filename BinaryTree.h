//class template BinaryTree header file: BinaryTree.h
#ifndef _BINARY_TREE
#define _BINARY_TREE
#include"BinaryNode.h"
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
}
template<class ItemType>
void BinaryTree<ItemType>::preOrderVisit(BinaryNode<ItemType> *treeRoot)
{
}
template<class ItemType>
void BinaryTree<ItemType>::inOrderVisit(BinaryNode<ItemType> *treeRoot)
{
}
template<class ItemType>
void BinaryTree<ItemType>::postOrderVisit(BinaryNode<ItemType> *treeRoot)
{
}
template<class ItemType>
void BinaryTree<ItemType>::creatBinaryTree()
{
}
template<class ItemType>
void BinaryTree<ItemType>::displayPreorder()
{
}
void BinaryTree<ItemType>::displayInorder()
{
}
template<class ItemType>
void BinaryTree<ItemType>::displayPostorder()
{
}
#endif

