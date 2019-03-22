#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>

#include "name.h"
#include "generalschedule.h"
#include "customerlist.h"

class Agent{
private:
    Name name;
    GeneralSchedule schedule;
    unsigned int employeeNumber;
    unsigned int extensionNumber;
    unsigned int workedHours;
    std::string speciality;
    CustomerList customerList;

public:
    Agent();
    Agent(const Agent&);

    void setName(const Name&);
    void setSchedule(const GeneralSchedule&);
    void setEmployeeNumber(const unsigned int&);
    void setExtensionNumber(const unsigned int&);
    void setWorkedHours(const unsigned int&);
    void setSpeciality(std::string&);

    std::string toString(const bool&) ;

    Name getName() const;
    GeneralSchedule getSchedule() const;
    unsigned int getEmployeeNumber() const;
    unsigned int getExtensionNumber() const;
    unsigned int getWorkedHours() const;
    std::string getSpeciality() const;
    CustomerList& getCustomerList();

    Agent& operator = (const Agent&);

    bool operator == (const Agent&) const;
    bool operator != (const Agent&) const;
    bool operator < (const Agent&) const;
    bool operator <= (const Agent&) const;
    bool operator > (const Agent&) const;
    bool operator >= (const Agent&) const;

    friend std::istream& operator >> (std::istream&, Agent&);
    friend std::ostream& operator << (std::ostream&, Agent&);
};


#endif // AGENT_H_INCLUDED
