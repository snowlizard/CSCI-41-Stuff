#ifndef PatientRecord_h
#define PatientRecord_h
#include <iostream>
#include <string>

using namespace std;

class PatientRecord {
    
private:
    string lastName;
    string firstName;
    string dob;
    string symptoms;
    int priority;
public:
    PatientRecord();
    PatientRecord(string last, string first, string birth, string sym, int num );
    void setLast(string lName);
    string getLast() const;
    void setFirst(string fName);
    string getFirst() const;
    void setDOB(string date);
    string getDOB() const;
    void setSymptoms(string sym);
    string getSymptoms() const;
    void setPriority(int p);
    int getPriority() const;
    bool operator<(const PatientRecord &record) const;
    friend ostream& operator<<( ostream &os, PatientRecord &rec );
};

PatientRecord::PatientRecord()
{
    lastName = "";
    firstName = "";
}
PatientRecord::PatientRecord(string last, string first, string birth, string sym, int num )
{
    lastName = last;
    firstName = first;
    dob = birth;
    symptoms = sym;
    priority = num;
}
void PatientRecord::setLast(string lName)
{
    lastName = lName;
}
string PatientRecord::getLast() const
{
    return lastName;
}
void PatientRecord::setFirst(string fName)
{
    firstName = fName;
}
string PatientRecord::getFirst() const
{
    return firstName;
}
void PatientRecord::setDOB(string date)
{
    dob = date;
}
string PatientRecord::getDOB() const
{
    return dob;
}
void PatientRecord::setSymptoms(string syms)
{
    symptoms = syms;
}
string PatientRecord::getSymptoms() const
{
    return symptoms;
}
void PatientRecord::setPriority(int p)
{
    priority = p;
}
int PatientRecord::getPriority() const
{
    return priority;
}

bool PatientRecord::operator<(const PatientRecord &record) const
{
    return ( getPriority() < record.getPriority() );
}
ostream& operator<<( ostream &os,const PatientRecord &rec )
{
    os << "===== Priority Number " << rec.getPriority() << " =====\n";
    os << "Last Name: " << rec.getLast() << endl;
    os << "First Name: " << rec.getFirst() << endl;
    os << "Date of birth: " << rec.getDOB() << endl;
    os << "The symptom: " << rec.getSymptoms();
    return os;
}




#endif /* PatientRecord_h */
