#ifndef _BINARYSEARCH_TREE
#define _BINARYSEARCH_TREE
#include"BinaryNode.h"
using namespace std;

template<class ItemType>
class BinarySearchTree
{
private:
    BinaryNode<ItemType> *rootPtr;
protected:
    void inOrderVisit(BinaryNode<ItemType> *treeRoot);
    int getNumberOfNodesHelper(BinaryNode<ItemType> *treeRoot);
    BinaryNode<ItemType> *insertNode(BinaryNode<ItemType> *treeRoot,
                                     BinaryNode<ItemType> *newNodePtr);
    BinaryNode<ItemType> *getNode(BinaryNode<ItemType> *treeRoot,
                                  const ItemType &target) const;
    BinaryNode<ItemType> *removeEntry(BinaryNode<ItemType> *treeRoot,
                                      ItemType &target, bool &success);
    BinaryNode<ItemType> *removeNode(BinaryNode<ItemType>
                                     *nodeToBeRemoved);
    BinaryNode<ItemType> *removeLeftMost(BinaryNode<ItemType> *treeRoot,
                                         ItemType &nodeItem);
public:
    //Constructors
    BinarySearchTree();
    //Set and Get functions
    ItemType getRootItem();
    void setRootItem(const ItemType &rootItem);
    //Other member functions
    bool isEmpty() const;
    int getNumberOfNodes();
    void displayInorder();
    void binarySearchAdd(ItemType newItem);
    bool binarySearchRemove(ItemType anItem);
};
//Constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
    rootPtr = NULL;
}
//Set and get functions for the item in the root
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootItem()
{
    if (rootPtr != NULL)
        return rootPtr->getItem();
    else {
        cout << "Empty tree!\n";
        exit(1);
    }
}
template<class ItemType>
void BinarySearchTree<ItemType>::setRootItem(const ItemType &rootItem)
{
    if (rootPtr != NULL)
        rootPtr->setItem(rootItem);
    else
        rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
//Protected functions
template<class ItemType>
void BinarySearchTree<ItemType>::inOrderVisit(BinaryNode<ItemType>
                                              *treeRoot)
{
    if (treeRoot== NULL)
        cout << "It is an empty tree!\n";
    else {
        if (treeRoot->getLeftChildPtr() != NULL)
            inOrderVisit(treeRoot->getLeftChildPtr());
        cout << treeRoot->getItem() << "\t";
        if (treeRoot->getRightChildPtr() != NULL)
            inOrderVisit(treeRoot->getRightChildPtr());
    }
}
template<class ItemType>
int
BinarySearchTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>
                                                   *treeRoot)
{
    int numberOfNodes = 0;
    if (treeRoot != NULL) {
        numberOfNodes = 1 +
        getNumberOfNodesHelper(treeRoot->getLeftChildPtr()) +
        getNumberOfNodesHelper(treeRoot->getRightChildPtr());
    }
    return numberOfNodes;
}
//Other public member functions
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return (rootPtr == NULL);
}
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes()
{
    return getNumberOfNodesHelper(rootPtr);
}
template<class ItemType>
void BinarySearchTree<ItemType>::displayInorder()
{
    inOrderVisit(rootPtr);
}
template<class ItemType>
BinaryNode<ItemType>
*BinarySearchTree<ItemType>::insertNode(BinaryNode<ItemType> *treeRoot,
                                        BinaryNode<ItemType> *newNodePtr)
{
    if (treeRoot == NULL)
        return newNodePtr;
    else
    {
        if ( newNodePtr->getItem() < treeRoot->getItem() )
            treeRoot->setLeftChildPtr(insertNode(treeRoot->getLeftChildPtr(), newNodePtr));
        else
            treeRoot->setRightChildPtr(insertNode(treeRoot->getRightChildPtr(), newNodePtr));
        return treeRoot;
    }
}
template<class ItemType>
BinaryNode<ItemType>
*BinarySearchTree<ItemType>::getNode(BinaryNode<ItemType> *treeRoot,
                                     const ItemType &target) const
{
    if( treeRoot == NULL )
        return NULL;
    else
    {
        if (treeRoot->getItem() == target)
            return treeRoot;
        else{
            getNode(treeRoot->getLeftChildPtr(), target);
            getNode(treeRoot->getRightChildPtr(), target);
        }
    }
}
template<class ItemType>
void BinarySearchTree<ItemType>::binarySearchAdd(ItemType newItem)
{
    BinaryNode<ItemType> *newNode = new BinaryNode<ItemType>(newItem);
    rootPtr = insertNode(rootPtr, newNode);
}
template<class ItemType>
BinaryNode<ItemType>
*BinarySearchTree<ItemType>::removeEntry(BinaryNode<ItemType> *treeRoot,
                                         ItemType &target, bool &success)
{
    if ( treeRoot== NULL)
    {
        cout << "ERROR! item not found\n";
        success = false;
        return NULL;
    }
    else if ( treeRoot->getItem() == target )
    {
        success = true;
        return removeNode(treeRoot);
    }
    if ( target < treeRoot->getItem() && treeRoot->getLeftChildPtr() != NULL)
    {
        treeRoot->setLeftChildPtr(removeEntry(treeRoot->getLeftChildPtr(), target, success));
    }
    else if ( treeRoot->getRightChildPtr() != NULL )
        treeRoot->setRightChildPtr(removeEntry(treeRoot->getRightChildPtr(), target, success));
    
    return treeRoot;
}
template<class ItemType>
BinaryNode<ItemType>
*BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>
                                        *nodeToBeRemoved)
{
    BinaryNode<ItemType> *node;
    
    if (nodeToBeRemoved->isLeaf())
    {
        delete (nodeToBeRemoved);
        return NULL;
    }
    else{
        if (nodeToBeRemoved->getLeftChildPtr() != NULL && nodeToBeRemoved->getRightChildPtr() == NULL)
        {
            node = nodeToBeRemoved->getLeftChildPtr();
            nodeToBeRemoved->setLeftChildPtr(NULL);
            delete (nodeToBeRemoved);
            return node;
        }
        else if (nodeToBeRemoved->getRightChildPtr() != NULL && nodeToBeRemoved->getLeftChildPtr() == NULL)
        {
            node = nodeToBeRemoved->getRightChildPtr();
            nodeToBeRemoved->setRightChildPtr(NULL);
            delete (nodeToBeRemoved);
            return node;
        }
        else{
            ItemType nodeItem = nodeToBeRemoved->getRightChildPtr()->getItem();
            nodeToBeRemoved->setRightChildPtr(removeLeftMost(nodeToBeRemoved->getRightChildPtr(), nodeItem));
            nodeToBeRemoved->setItem(nodeItem);
            return nodeToBeRemoved;
           
        }
    }
}
template<class ItemType>
BinaryNode<ItemType>
*BinarySearchTree<ItemType>::removeLeftMost(BinaryNode<ItemType>
                                            *treeRoot,
                                            ItemType &nodeItem)
{
    if ( treeRoot->getLeftChildPtr() != NULL )
    {
        treeRoot->setLeftChildPtr(removeLeftMost(treeRoot->getLeftChildPtr(), nodeItem));
    }
    else{
        nodeItem = treeRoot->getItem();
        return removeNode(treeRoot);
    }
    return treeRoot;
}
template<class ItemType>
bool BinarySearchTree<ItemType>::binarySearchRemove(ItemType anItem)
{
    bool success;
    rootPtr = removeEntry(rootPtr, anItem, success);
    if ( success == false )
    {
        cout << "Removal failed.\n";
    }
    return success;
}
#endif
