
#ifndef _QUEUE
#define _QUEUE
#include"Node.h"
template<class ItemType>
class Queue
{
private:
    Node<ItemType> *backPtr;
    Node<ItemType> *frontPtr;
public:
    Queue();  //Default constructor
    Queue(const Queue<ItemType> &aQueue); //Copy constructor
    bool isEmpty() const;
    bool enqueue(const ItemType &newEntry);
    bool dequeue();
    ItemType peekFront() const;
    void display() const;
};
template<class ItemType>
Queue<ItemType>::Queue()
{
    frontPtr = NULL;
    backPtr  = NULL;
}
template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue)
{
    Node<ItemType> *originalNodePtr=aQueue.frontPtr;
    if(originalNodePtr==NULL){
        frontPtr=NULL;
        backPtr=NULL;
    }
    else{
        //copy the first node
        frontPtr=new Node<ItemType>;
        frontPtr->setItem(originalNodePtr->getItem());
        //copy the remaining nodes
        backPtr=frontPtr;
        while(originalNodePtr->getNext()!=NULL){
            originalNodePtr=originalNodePtr->getNext();
            ItemType nextItem=originalNodePtr->getItem();
            Node<ItemType> *newNode=new
            Node<ItemType>(nextItem);
            backPtr->setNext(newNode);
            backPtr=backPtr->getNext();
        }
        backPtr->setNext(NULL);
    }
}
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
    return ( frontPtr == NULL );
}
template<class ItemType>
bool Queue<ItemType>::enqueue(const ItemType &newEntry)
{
    Node<ItemType> *newNode = new Node<ItemType>( newEntry );
    if ( isEmpty() )
    {
        frontPtr = newNode;
        backPtr  = newNode;
        return true;
    }
    else
    {
        backPtr->setNext( newNode );
        backPtr = newNode;
        return true;
    }
}
template<class ItemType>
bool Queue<ItemType>::dequeue()
{
    if ( isEmpty() )
    {
        return false;
    }
    else
    {
        if ( frontPtr == backPtr )
        {
            delete ( frontPtr );
            frontPtr = NULL;
            backPtr  = NULL;
            return true;
        }
        else
        {
            Node<ItemType> *curNode = frontPtr;
            frontPtr = curNode->getNext();
            curNode->setNext( NULL );
            delete( curNode );
            return true;
        }
    }
}
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const
{
}
template<class ItemType>
void Queue<ItemType>::display() const
{
}
#endif

