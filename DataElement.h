#indef DataElement_h
#define DataElement_h

class DataElement
{
private:
    int arrivalTime;
    int transectionTime;
public:
    DataElement();
    DataElement(int arTime, int traTime);
    void setArrivalTime(int arTime);
    int getArrivalTime();
    void setTransectionTime(int traTime);
    int getTransectionTime();
    friend ostream &operator<<(ostream &, DataElement &);
};

#endif
