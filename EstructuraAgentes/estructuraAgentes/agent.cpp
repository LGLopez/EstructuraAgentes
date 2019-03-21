#include"agent.h"

Agent::Agent() {}

Agent::Agent(const Agent& aAgent) : name(aAgent.name), schedule(aAgent.schedule), employeeNumber(aAgent.employeeNumber), extensionNumber(aAgent.extensionNumber), workedHours(aAgent.workedHours), speciality(aAgent.speciality), customerList(aAgent.customerList) {}

void Agent::setName(const Name& aName) {
    name = aName;
    }

void Agent::setSchedule(const GeneralSchedule& aGeneralSchedule) {
    schedule = aGeneralSchedule;
    }

void Agent::setEmployeeNumber(const unsigned int& aEmployeeNumber) {
    employeeNumber = aEmployeeNumber;
    }

void Agent::setExtensionNumber(const unsigned int& aExtensionNumber) {
    extensionNumber = aExtensionNumber;
    }

void Agent::setWorkedHours(const unsigned int& aWorkedHours) {
    workedHours = aWorkedHours;
    }

void Agent::setSpeciality(const std::string& aSpeciality) {
    speciality = aSpeciality;
    }

std::string Agent::toString(const bool& addList) const {
    std::string stringToShow;

    stringToShow += "Nombre:           " + name.toString() + "\n";
    stringToShow += schedule.toString() + "\n";
    stringToShow += "Num. Empleado:    " + std::to_string(employeeNumber) + "\n";
    stringToShow += "Num. Extension:   " + std::to_string(extensionNumber) + "\n";
    stringToShow += "Horas trabajadas: " + std::to_string(workedHours) + "\n";
    stringToShow += "Especialidad:     " + speciality + "\n";

    if(addList == true){
        stringToShow += "\nLista de clientes:\n";
        stringToShow += customerList.toString();
        stringToShow += "\n\n";
        }

    return stringToShow;
    }

Name Agent::getName() const {
    return name;
    }

GeneralSchedule Agent::getSchedule() const {
    return schedule;
    }

unsigned int Agent::getEmployeeNumber() const{
    return employeeNumber;
    }


unsigned int Agent::getExtensionNumber() const {
    return extensionNumber;
    }

unsigned int Agent::getWorkedHours() const {
    return workedHours;
    }

std::string Agent::getSpeciality() const {
    return speciality;
    }

CustomerList& Agent::getCustomerList(){
    return customerList;
    }


Agent& Agent::operator=(const Agent& aAgent) {
    name = aAgent.name;
    schedule = aAgent.schedule;
    employeeNumber = aAgent.employeeNumber;
    extensionNumber = aAgent.extensionNumber;
    workedHours = aAgent.workedHours;
    speciality = aAgent.speciality;
    customerList = aAgent.customerList;

    return *this;
    }

bool Agent::operator==(const Agent& aAgent) const {
    return name == aAgent.name;
    }

bool Agent::operator!=(const Agent& aAgent) const {
    return name != aAgent.name;
    }

bool Agent::operator<(const Agent& aAgent) const {
    return name < aAgent.name;
    }

bool Agent::operator<=(const Agent& aAgent) const {
    return name <= aAgent.name;
    }

bool Agent::operator>(const Agent& aAgent) const {
    return name > aAgent.name;
    }

bool Agent::operator>=(const Agent& aAgent) const {
    return name >= aAgent.name;
    }


std::istream& operator >> (std::istream&, Agent&){}
std::ostream& operator << (std::ostream&, Agent&){}
