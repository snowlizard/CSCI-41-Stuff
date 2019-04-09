#include<iostream>
#include"DataElement.h"
#include"SortedList.h"
#include"Event.h"
#include"Queue.h"
#include<stdlib.h>
#include <iomanip>
using namespace std;
const int SIZE = 10;
void processArrival(int &customer, DataElement  iFile[], int  length, SortedList<Event>  &eList, Queue<DataElement>  &bQueue);
void processDeparture(SortedList<Event>  &eList, Queue<DataElement>  &bQueue, int &wTime);


int main()
{
    
    int depart[SIZE];
    int Twt[SIZE];
    int wT[SIZE];
    DataElement bankData[SIZE] = { DataElement(1,5),DataElement(2,3),DataElement(4,2), DataElement(20,2),DataElement(22,6),DataElement(24,4), DataElement(26,1), DataElement(28,3), DataElement(30,2), DataElement(88,5) };
    Queue<DataElement> bankQueue;
    
    
    SortedList<Event> eventList;
    Event aEvent1('A', 1);
    wT[0] = 0;
    eventList.insertSorted(aEvent1);
    int customer = 0;
    int waitingTime;
    int counter = 1;
    double totalWaitingTime = 0;
    while (!eventList.isEmpty())
    {
        if (eventList.getEntry(1).getEventStatus() == 'A')
        {
            processArrival(customer, bankData, SIZE, eventList, bankQueue);
            customer++;
        }
        else
        {
            if (counter != SIZE + 1)
            {
                depart[counter - 1] = eventList.getEntry(1).getOccurTime();
            }
            processDeparture(eventList, bankQueue, waitingTime);
            if (counter != SIZE)
            {
                wT[counter] = waitingTime;
                totalWaitingTime = totalWaitingTime + waitingTime;
                counter++;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        Twt[i] = bankData[i].getArrivalTime() + wT[i];
    }
    cout << "\n\n";
    cout << "Customer Number\t" << setw(20) << " Arrival Time\t" << setw(20) << " Transaction Begins\t" << setw(20) << " Transaction Time\t" << setw(20) << " Departure Time\t" << setw(20) << " Waiting Time\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << "\t" << setw(20) << bankData[i].getArrivalTime() << "\t" << setw(20) << Twt[i] << "\t" << setw(20) << bankData[i].getTransactionTime() << "\t" << setw(20) << depart[i] << "\t" << setw(20) << wT[i] << "\n";
    }
    cout << endl;
    double aveTime = static_cast<double>(totalWaitingTime) / SIZE;
    cout << "The average wait time is  " << aveTime << endl;
    
    return 0;
}



void processArrival(int &customer,DataElement  iFile[], int  length, SortedList<Event>  &eList, Queue<DataElement>  &bQueue)
{
    if (bQueue.isEmpty())
    {
        Event anE('D', iFile[customer].getArrivalTime() + iFile[customer].getTransactionTime());
        eList.insertSorted(anE);
    }
    bQueue.enqueue(iFile[customer]);
    eList.remove(1);
    if (customer != length - 1)
    {
        Event secE('A', iFile[customer + 1].getArrivalTime());
        eList.insertSorted(secE);
    }
}

void processDeparture(SortedList<Event>  &eList, Queue<DataElement>  &bQueue, int &wTime)
{
    bQueue.dequeue();
    if (!bQueue.isEmpty())
    {
        Event nextE('D', (eList.getEntry(1).getOccurTime()) + bQueue.peekFront().getTransactionTime());
        eList.insertSorted(nextE);
        wTime = eList.getEntry(1).getOccurTime() - bQueue.peekFront().getArrivalTime();
    }
    else if (bQueue.isEmpty())
    {
        wTime = 0;
    }
    eList.remove(1);
}

