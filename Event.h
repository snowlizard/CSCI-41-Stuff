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
    char getEventStatus() const;
    void setOccurTime(int oTime);
    int getOccurTime() const;
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

char Event::getEventStatus() const
{
    return eventStatus;
}

void Event::setOccurTime( int oTime )
{
    occurTime = oTime;
}

int Event::getOccurTime() const
{
    return occurTime;
}
//==================== Operator Overloading =======

bool Event::operator>( const Event &anEvent ) const
{
    if ( getOccurTime() > anEvent.getOccurTime() )
    {
        return true;
    }
    else{
        return false;
    }
}

bool Event::operator==( const Event &anEvent ) const
{
    if ( getEventStatus() == anEvent.getEventStatus() )
    {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<( ostream &out, Event &anEvent )
{
    out << "Event status: " << anEvent.getEventStatus() << endl;
    out << "Event time: " << anEvent.getOccurTime() << endl;
    return out;
}

#endif 
