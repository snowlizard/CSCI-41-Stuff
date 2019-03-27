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
    system("pause");
    return 0;
}
void processArrival(int &customer,
                    DataElement  iFile[], int  length,
                    SortedList<Event>  &eList, Queue<DataElement>  &bQueue)
{
    if ( bQueue.isEmpty() )
    {
        //eList.insertSorted(<#const Event &newEntry#>)
    }
}
void processDeparture(SortedList<Event>  &eList, Queue<DataElement>
                      &bQueue, int &wTime)
{
}
