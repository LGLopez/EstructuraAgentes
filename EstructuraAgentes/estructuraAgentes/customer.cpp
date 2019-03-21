#include "customer.h"

Customer::Customer() {}

Customer::Customer(const Name& aName, const Time& aCallTime, const int& aDuration) : name(aName), callTime(aCallTime), duration(aDuration) { }

Customer::Customer(const Customer& aCustomer) : name(aCustomer.name), callTime(aCustomer.callTime), duration(aCustomer.duration)   {}


void Customer::setName(const Name& aName) {
    name = aName;
    }

void Customer::setCallTime(const Time& aCallTime) {
    callTime = aCallTime;
    }

void Customer::setDuration(const int& aDuration) {
    duration = aDuration;
    }

std::string Customer::toString() const{
    std::string result;

    result = result + "Nombre:           " + name.toString() + "\n";
    result = result + "Hora de llamada:  " + callTime.toString() + "\n";
    result = result + "Duracion llamada: " + std::to_string(duration) + " seg." + "\n";
    return result;


//    return "Nombre: " + name.toString() + "\n" +
//           "Hora de llamada: " + callTime.toString() + "\n" +
//           "Duracion llamada: " + std::to_string(duration) + " seg." + "\n";
    }

Name Customer::getName() const{
    return name;
    }

Time Customer::getCallTime() const{
    return callTime;
    }

int Customer::getDuration() const{
    return duration;
    }

Customer& Customer::operator=(const Customer& aCustomer){
    name = aCustomer.name;
    callTime = aCustomer.callTime;
    duration = aCustomer.duration;

    return *this;
    }


bool Customer::operator==(const Customer& aCustomer) const{
    return name == aCustomer.name;
    }

bool Customer::operator!=(const Customer& aCustomer) const{
    return name != aCustomer.name;
    }

bool Customer::operator>(const Customer& aCustomer) const{
    return name > aCustomer.name;
    }

bool Customer::operator>=(const Customer& aCustomer) const{
    return name >= aCustomer.name;
    }

bool Customer::operator<=(const Customer& aCustomer) const{
    return name <= aCustomer.name;
    }

bool Customer::operator<(const Customer& aCustomer) const{
    return name < aCustomer.name;
    }

std::ostream& operator << (std::ostream& os, Customer& aCustomer){
//    os << aCustomer.name << std::endl;
//    os << aCustomer.callTime << std::endl;
//    os << aCustomer.duration;
//
//    return os;
    }

std::istream& operator >> (std::istream& is, Customer& aCustomer){
//    is >> aCustomer.name;
//    is >> aCustomer.callTime;
//    is >> aCustomer.duration;
//
//    return is;
    }
