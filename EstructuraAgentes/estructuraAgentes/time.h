#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

class Time{
private:
    unsigned int hours;
    unsigned int minutes;

    unsigned int toCompare() const;

    bool isValidTime(const int&, const int&);

public:
    Time();
    Time(const unsigned int&, const unsigned int&);
    Time(const Time&);

    unsigned int getHours() const;
    unsigned int getMinutes() const;

    std::string toString() const;

    void setHours(const unsigned int&);
    void setMinutes(const unsigned int&);

    Time& operator = (const Time&);

    bool operator == (const Time&)const;
    bool operator != (const Time&)const;
    bool operator <  (const Time&)const;
    bool operator <= (const Time&)const;
    bool operator >  (const Time&)const;
    bool operator >= (const Time&)const;

    friend std::ostream& operator << (std::ostream&, Time&);
    friend std::istream& operator >> (std::istream&, Time&);
};

#endif // TIME_H_INCLUDED
