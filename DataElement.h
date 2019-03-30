#ifndef DataElement_h
#define DataElement_h

using namespace std;

class DataElement
{
private:
    int arrivalTime;
    int transactionTime;
public:
    DataElement();
    DataElement(int arTime, int traTime);
    void setArrivalTime(int arTime);
    int getArrivalTime();
    void setTransactionTime(int traTime);
    int getTransactionTime();
    friend ostream &operator<<(ostream &, DataElement &);
};

DataElement::DataElement()
{
    arrivalTime = 0;
    transactionTime = 0;
}

DataElement::DataElement( int arTime, int traTime )
{
    arrivalTime     = arTime;
    transactionTime = traTime;
}

void DataElement::setArrivalTime( int arTime )
{
    arrivalTime = arTime;
}

int DataElement::getArrivalTime()
{
    return arrivalTime;
}

void DataElement::setTransactionTime( int traTime )
{
    transactionTime = traTime;
}

int DataElement::getTransactionTime()
{
    return transactionTime;
}


ostream& operator<<( ostream &, DataElement & )
{
    
}

#endif
