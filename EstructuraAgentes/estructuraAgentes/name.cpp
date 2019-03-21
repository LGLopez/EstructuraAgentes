#include "name.h"

Name::Name() {}

Name::Name(const std::string& aFirstName, const std::string& aLastName) : firstName(aFirstName), lastName(aLastName) {}

Name::Name(const Name& aName) :firstName(aName.firstName), lastName(aName.lastName) {}


std::string Name::getFirstName() const {
    return firstName;
    }

std::string Name::getLastName() const {
    return lastName;
    }

std::string Name::toString() const {
    return lastName + " " + firstName;
    }

void Name::setFirstName(const std::string& aFirstName) {
    firstName = aFirstName;
    }

void Name::setLastName(const std::string& aLastName) {
    lastName = aLastName;
    }

Name& Name::operator=(const Name& aName) {
    firstName = aName.firstName;
    lastName = aName.lastName;

    return *this;
    }

bool Name::operator==(const Name& aName)const {
    return toString() == aName.toString();
    }

bool Name::operator!=(const Name& aName)const {
    return toString() != aName.toString();
    }

bool Name::operator>=(const Name& aName)const {
    return toString() >= aName.toString();
    }

bool Name::operator>(const Name& aName)const {
    return toString() > aName.toString();
    }

bool Name::operator<=(const Name& aName)const {
    return toString() <= aName.toString();
    }

bool Name::operator<(const Name& aName)const {
    return toString() < aName.toString();
    }

std::ostream& operator << (std::ostream& os, Name& aName) {
    os << aName.firstName << std::endl;
    os << aName.lastName;

    return os;
    }

std::istream& operator >> (std::istream& is, Name& aName) {

    getline(is, aName.firstName);
    getline(is, aName.lastName);

    return is;
    }

