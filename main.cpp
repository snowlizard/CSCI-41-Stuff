//Phase II Testing Program

#include<iostream>
#include"DataElement.h"
#include"SortedList.h"
#include"Event.h"
#include"Queue.h"
using namespace std;

const int SIZE = 6;
void processArrival(int &customer,
                    DataElement  iFile[], int  length,
                    SortedList<Event>  &eList, Queue<DataElement>  &bQueue);

void processDeparture(SortedList<Event>  &eList, Queue<DataElement>  &bQueue, int &wTime);


int main()
{
    DataElement bankData[SIZE] = {
        DataElement(20,5),DataElement(22,4),DataElement(23,2),
        DataElement(30,3),DataElement(40,3),DataElement(41,4) };
    //Declare an instance of class template Queue
    Queue<DataElement> bankQueue;
    //Declare an instance of class template List
    SortedList<Event> eventList;
    int customer = 0;
    int waitingTime;
    int counter = 1;
    
    
    Event fcustomer( 'A', 20 );
    eventList.insertSorted( fcustomer );
    //cout << "=========================================================================\n";
    //cout << "Customer\tArrival Time\tTransaction begins\tDeparture Time\tWaiting time\n";
    while ( !eventList.isEmpty() )
    {
        cout << customer << "\t\t\t" << eventList.getEntry(1).getOccurTime() << "\t";
        cout << eventList.getEntry(1).getEventStatus();
        if ( eventList.getEntry(1).getEventStatus() == 'A' )
        {
            processArrival(customer, bankData , SIZE, eventList, bankQueue );
            customer++;
        }
        else{
            
            processDeparture( eventList, bankQueue, waitingTime );
            //cout << "waited for :" << waitingTime;
        }
        counter++;
        cout << endl;
    }
    
    return 0;
}

/**
int main()
{
    //Set up an array of DataElement with the data the bank provided:
    DataElement bankData[SIZE] = {
        DataElement(20,5),DataElement(22,4),DataElement(23,2),
        DataElement(30,3),DataElement(40,3),DataElement(41,4) };
    //Declare an instance of class template Queue
    Queue<DataElement> bankQueue;
    //Declare an instance of class template List
    SortedList<Event> eventList;
    int customer = 0;
    int waitingTime;
    int counter = 1;
    int totalWaitingTime = 0;
    //Testing the function processArrial():
    Event aEvent1('A', 20);  //create an arrival event
    eventList.insertSorted(aEvent1); //insert above arrival event into eventList
    processArrival(customer, bankData, SIZE, eventList, bankQueue);
    //Above function
    //1. insert a departure event ('D',25) into eventList
    //2. add current customer (20,5) to the bankQueue
    //3. remove first event from the eventList
    //4. insert next arrival event ('A',22) to the eventList
    //Check above actions:
    Event c = eventList.getEntry(1);
    cout << "this must be 22\n";
    cout << c << endl; //take a look a the first event in the eventList('A',22)
    eventList.remove(1); //remove the first event from the eventList
    cout << eventList.getEntry(1).getOccurTime() << endl;//and take a
    //look at the second event in eventList ('D',25)
    //Take a look at the customer who is in front of the queue (20,5)
    DataElement d = bankQueue.peekFront();
    cout << d << endl;
    cout << "===================\n";
    //Testing the function processDeparture():
    DataElement newCustomer(22, 4);
    bankQueue.enqueue(newCustomer);
    cout << "A customer is leaveing at " <<
    eventList.getEntry(1).getOccurTime() << endl;
    processDeparture(eventList, bankQueue, waitingTime);
    cout << "Next customer's transection begins, and waiting time is "
    << waitingTime << endl;
    c = eventList.getEntry(1);
    cout << c << endl; //take a look a the first event in the eventList('D',29)
    return 0;
}

**/

void processArrival(int &customer, DataElement  iFile[], int  length,
                    SortedList<Event>  &eList, Queue<DataElement>  &bQueue)
{
    int adTime, tTime, oTime;
    if ( bQueue.isEmpty() )
    {
        DataElement pCust = iFile[customer];
        adTime = pCust.getArrivalTime();
        tTime  = pCust.getTransactionTime();
        oTime  = adTime + tTime;
        Event nEvent( 'D' , oTime );
        eList.insertSorted( nEvent );
    }
    
    bQueue.enqueue(iFile[customer]);
    eList.remove(1);
    if ( customer != length -1 )
    {
        
        DataElement nCust = iFile[customer+1];
        Event nextEvent( 'A', nCust.getArrivalTime() );
        eList.insertSorted(nextEvent);
    }
    //cout << customer << "cust\n";
}
void processDeparture(SortedList<Event>  &eList, Queue<DataElement>
                      &bQueue, int &wTime)
{
    int time1 = eList.getEntry(1).getOccurTime();
    bQueue.dequeue();
    eList.remove(1);
    if ( !bQueue.isEmpty() )
    {
        
        //int time1 = eList.getEntry(1).getOccurTime();// previous cust
        int time2 = bQueue.peekFront().getTransactionTime();
        int total = time1 + time2;
        wTime = time1 - bQueue.peekFront().getArrivalTime();
        cout << " wait " << wTime;
        if (wTime == 0 ) { cout << "0";}
        Event dEvent('D', total );
        eList.insertSorted( dEvent );
    }
    //bQueue.dequeue();
    //eList.remove(1);
}

/**
 psuedo code for main while loop
 
 1. create an ArrivalEvent & insert into eventlist
 2. while ( eventList is not Empty )
 {
    "look" at event infront of eventList
    if ( it is an arrivalEvent )
    {
        processArrival();
    }
    else
    {
        processDeparture;
    }
 }
 
 **/
