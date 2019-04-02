#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>
#include <cstdlib>
#include <iostream>

#include "name.h"
#include "time.h"

class Customer{
private:
    Name name;
    Time callTime;
    int duration;

public:
    Customer();
    Customer(const Name&, const Time&, const int&);
    Customer(const Customer&);

    void setName(const Name&);
    void setCallTime(const Time&);
    void setDuration(const int&);

    std::string toString()const;

    Name getName()const;
    Time getCallTime()const;
    int  getDuration()const;

    Customer& operator = (const Customer&);

    bool operator == (const Customer&)const;
    bool operator != (const Customer&)const;
    bool operator > (const Customer&)const;
    bool operator >= (const Customer&)const;
    bool operator <= (const Customer&)const;
    bool operator < (const Customer&)const;

    friend std::ostream& operator << (std::ostream&, Customer&);
    friend std::istream& operator >> (std::istream&, Customer&);
};

#endif // CUSTOMER_H_INCLUDED
