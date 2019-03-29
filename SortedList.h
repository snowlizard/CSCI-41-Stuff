#ifndef _SORTED_LIST
#define _SORTED_LIST
#include"Node.h"

using namespace std;

template<class ItemType>
class SortedList
{
private:
    Node<ItemType> *head;
    int itemCount;         //Current count of list items
    Node<ItemType>* getNodeBefore(const ItemType &anEntry)const;
    Node<ItemType>* getNodeAt(int position) const;
    
public:
    SortedList(); //Default constructor
    SortedList(const SortedList<ItemType> &aList); //Copy constructor
    bool isEmpty() const;  //Check if the list empty (no item stored in the array)
    int getLength() const; //Returns the number of items in the list
    bool remove(int position); //Remove an entry at given position from the list
    void clear(); //remove all the items from the list
    ItemType getEntry(int position) const; //Retrieves an item on the list at the given position
    void displayList();
    //Following are three new methods:
    void insertSorted(const ItemType &newEntry);
    bool removeSorted(const ItemType &anEntry);
    int getPosition(const ItemType &newEntry) const;
};
//Complete all the constructors and methods here:
template<class ItemType>
SortedList<ItemType>::SortedList()
{
    head = NULL;
    itemCount = 0;
}

template<class ItemType>
SortedList<ItemType>::SortedList( const SortedList<ItemType> &aList )
{
    if ( aList.isEmpty() )
    {
        head = NULL;
        itemCount = 0;
    }
    else
    {
        Node<ItemType> *origNode = aList.head, *curNode, *ptr;
        head = new Node<ItemType>( origNode->getItem() );
        curNode = head;
        while ( origNode->getNext() != NULL )
        {
            origNode = origNode->getNext();
            ptr = new Node<ItemType>( origNode->getItem() );
            curNode->setNext( ptr );
            curNode = curNode->getNext();
        }
    }
}

template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeBefore( const ItemType &anEntry) const
{
    
    Node<ItemType> *curNode = head;
    Node<ItemType> *preNode = NULL;
    while ( (curNode != NULL) && ( curNode->getItem() < anEntry)  )
    {
        preNode = curNode;
        curNode = curNode->getNext();
    }
    return preNode;
}

template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeAt( int position ) const
{
    if ( position <= 0 || position > getLength() )
    {
        return NULL;
    }
    else
    {
        Node<ItemType> *curNode = head;
        for ( int i = 0; i < ( position - 1 ) ; i++ )
        {
            curNode = curNode->getNext();
        }
        return curNode;
    }
}


template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
    return ( head == NULL );
}

template<class ItemType>
int SortedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
bool SortedList<ItemType>::remove( int position )
{
    if( isEmpty() )
    {
        cout << "List is empty!\n";
        return false;
    }
    else if ( position == 1 )
    {
        Node<ItemType> *curNode = head;
        head = head->getNext();
        curNode->setNext( NULL );
        delete( curNode );
        itemCount--;
        return true;
    }
    else
    {
        Node<ItemType> *curNode = getNodeAt( position );
        Node<ItemType> *preNode = getNodeAt( position - 1 );
        preNode->setNext( curNode->getNext() );
        curNode->setNext( NULL );
        delete ( curNode );
        itemCount--;
        return true;
    }
}

template<class ItemType>
void SortedList<ItemType>::clear()
{
    while ( !isEmpty() )
    {
        remove(1);
    }
}

template<class ItemType>
ItemType SortedList<ItemType>::getEntry( int position ) const
{
    Node<ItemType> *curNode = getNodeAt( position );
    if ( curNode != NULL )
    {
        return curNode->getItem();
    }
    else
    {
        cout << "Invalid Input!\n";
        exit(0);
    }
}

template<class ItemType>
void SortedList<ItemType>::displayList()
{
    if ( isEmpty() )
    {
        cout << "List is empty!\n";
    }
    else
    {
        Node<ItemType> *curNode = head;
        while ( curNode != NULL )
        {
            cout << curNode->getItem() << endl;
            curNode = curNode->getNext();
        }
    }
}

template<class ItemType>
void SortedList<ItemType>::insertSorted( const ItemType &newEntry )
{
    Node<ItemType> *newNode = new Node<ItemType>( newEntry );
    Node<ItemType> *preNode = getNodeBefore( newEntry );
    
    if ( preNode == NULL )
    {
        newNode->setNext( head );
        head = newNode;
        itemCount++;
    }
    else
    {
        newNode->setNext( preNode->getNext() );
        preNode->setNext( newNode );
        itemCount++;
    }
}

 template<class ItemType>
 bool SortedList<ItemType>::removeSorted( const ItemType &anEntry )
 {
     Node<ItemType>* curNode = head;
     //Node<ItemType>* tmpNode = curNode;
     bool succuess = false;
     
     while ( curNode != NULL )
     {
         if ( curNode->getItem() == anEntry )
         {
             int iPos = getPosition(anEntry);
             remove( iPos );
             succuess = true;
         }
         
         curNode = curNode->getNext();
     }
     return succuess;
 }


template<class ItemType>
int SortedList<ItemType>::getPosition( const ItemType &newEntry ) const
{
    
    int counter = 1;
    Node<ItemType> *curNode = head;
    SortedList<ItemType> tmpList;
    
    int n = newEntry;
    tmpList.insertSorted(n);
    
    while ( curNode != NULL )
    {
        tmpList.insertSorted(curNode->getItem() );
        curNode = curNode->getNext();
    }
    
    while ( !tmpList.isEmpty() )
    {
        if ( tmpList.getEntry(counter) == newEntry )
        {
            return counter;
        }
        
        counter++;
        
    }
    
    return counter;
}
#endif

