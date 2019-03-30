#ifndef Event_h
#define Event_h

class Event
{
private:
    char eventStatus;
    int occurTime;
public:
    Event();
    Event(char eState, int oTime);
    void setEventStatus(char eStatus);
    char getEventStatus();
    void setOccurTime(int oTime);
    int getOccurTime();
    //operatro overloading
    bool operator>(const Event &anEvent) const;
    bool operator==(const Event &anEvent) const;
    friend ostream &operator<<(ostream &out, Event &anEvent);
};

Event::Event()
{
    eventStatus = 'A';
    occurTime   = 0;
}

Event::Event( char eState, int oTime )
{
    eventStatus = eState;
    occurTime  = oTime;
}

void Event::setEventStatus( char eStatus )
{
    eventStatus = eStatus;
}

char Event::getEventStatus()
{
    return eventStatus;
}

void Event::setOccurTime( int oTime )
{
    occurTime = oTime;
}

int Event::getOccurTime()
{
    return occurTime;
}
//==================== Operator Overloading =======

bool Event::operator>( const Event &anEvent ) const
{
    return  > anEvent;
}

bool Event::operator==( const Event &anEvent ) const
{
    
}

#endif 
