#ifndef Event_h
#define Event_h

class Event
{
private:
    char eventStatus;
    int occurTime;
public:
    Event();
    Event(char eStatue, int oTime);
    void setEventStatus(char eStatus);
    char getEventStatus();
    void setOccurTime(int oTime);
    int getOccurTime();
    //operatro overloading
    bool operator>(const Event &anEvent) const;
    bool operator==(const Event &anEvent) const;
    friend ostream &operator<<(ostream &out, Event &anEvent);
};


#endif 
