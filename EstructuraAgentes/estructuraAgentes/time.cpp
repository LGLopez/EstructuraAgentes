#include "time.h"

unsigned int Time::toCompare() const {
    return hours * 100 + minutes;
    }

bool Time::isValidTime(const int& aHour, const int& aMinute) {
    return aHour >= 0 and aHour <= 23 and aMinute >=0 and aMinute <=59;
    }

Time::Time() {}

Time::Time(const unsigned int& aHour, const unsigned int& aMinute) :hours(aHour), minutes(aMinute) {}

Time::Time(const Time& aTime) : hours(aTime.hours), minutes(aTime.minutes) {}


unsigned int Time::getHours() const{
    return hours;
    }

unsigned int Time::getMinutes() const{
    return minutes;
    }


std::string Time::toString() const{
    char stringTime[6];
    sprintf(stringTime, "%02d:%02d", hours, minutes);
    return stringTime;
    }

void Time::setHours(const unsigned int& aHours) {
    hours = aHours;
    }

void Time::setMinutes(const unsigned int& aMinutes) {
    minutes = aMinutes;
    }
Time& Time::operator=(const Time& aTime) {
    minutes = aTime.minutes;
    hours = aTime.hours;

    return *this;
    }

bool Time::operator==(const Time& aTime) const{
    return toCompare() == aTime.toCompare();
    }

bool Time::operator!=(const Time& aTime) const{
    return toCompare() != aTime.toCompare();
    }

bool Time::operator<(const Time& aTime) const{
    return toCompare() < aTime.toCompare();
    }

bool Time::operator<=(const Time& aTime) const{
    return toCompare() <= aTime.toCompare();
    }

bool Time::operator>(const Time& aTime) const{
    return toCompare() > aTime.toCompare();
    }

bool Time::operator>=(const Time& aTime) const{
    return toCompare() >= aTime.toCompare();
    }

std::ostream& operator << (std::ostream& os, Time& aTime){
    os << aTime.hours << std::endl;
    os << aTime.minutes;

    return os;
    }
std::istream& operator >> (std::istream& is, Time& aTime){
    std::string myString;

    getline(is, myString);
    aTime.hours = atoi(myString.c_str());
    getline(is, myString);
    aTime.minutes = atoi(myString.c_str());

    return is;
    }
