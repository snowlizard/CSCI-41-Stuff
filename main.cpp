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
    int waitingTime=0;
    int counter = 1;
    int totalWait=0;
    
    
    Event fcustomer( 'A', 20 );
    eventList.insertSorted( fcustomer );
    cout << "=========================================================================\n";
    cout << "Customer\tArrival Time\tTransaction begins\tDeparture Time\tWaiting time\n";
    while ( !eventList.isEmpty() )
    {
    
        if ( eventList.getEntry(1).getEventStatus() == 'A' )
        {
            processArrival(customer, bankData , SIZE, eventList, bankQueue );
            customer++;
        }
        else{
            cout << counter << "\t\t\t" << bankData[counter-1].getArrivalTime();
            cout << "\t\t\t\t" << bankData[counter-1].getArrivalTime() + waitingTime;
            cout << "\t\t\t\t\t" << eventList.getEntry(1).getOccurTime();
            cout << "\t\t\t\t" << waitingTime;
            processDeparture( eventList, bankQueue, waitingTime );
            totalWait+=waitingTime;
            counter++;
            cout << endl;
        }
    }
    
    cout << "Total wait time of: " << totalWait << endl;
    return 0;
}

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
        int time2 = bQueue.peekFront().getTransactionTime();
        int total = time1 + time2;
        wTime = time1 - bQueue.peekFront().getArrivalTime();
        
        Event dEvent('D', total );
        eList.insertSorted( dEvent );
    }
    else{ wTime = 0; }

}

