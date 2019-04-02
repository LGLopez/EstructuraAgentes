#include"generalschedule.h"

GeneralSchedule::GeneralSchedule() {}

GeneralSchedule::GeneralSchedule(const Time& aStartTime, const Time& aEndTime) : startTime(aStartTime), endTime(aEndTime) {}

GeneralSchedule::GeneralSchedule(const GeneralSchedule& aGeneralSchedule) : startTime(aGeneralSchedule.startTime), endTime(aGeneralSchedule.endTime) {}

GeneralSchedule& GeneralSchedule::operator=(const GeneralSchedule& aGeneralSchedule) {
    startTime = aGeneralSchedule.startTime;
    endTime = aGeneralSchedule.endTime;

    return *this;
    }

Time GeneralSchedule::getStartTime() const {
    return startTime;
    }

Time GeneralSchedule::getEndTime() const {
    return endTime;
    }

std::string GeneralSchedule::toString() const {
    return "Hora de Entrada:  " + startTime.toString() + "\n" + "Hora de Salida:   " + endTime.toString();
    }

void GeneralSchedule::setStartTime(const Time& aStartTime) {
    startTime = aStartTime;
    }

void GeneralSchedule::setEndTime(const Time& aEndTime) {
    endTime = aEndTime;
    }

bool GeneralSchedule::operator==(const GeneralSchedule& aGeneralSchedule) const {
    return (endTime == aGeneralSchedule.getEndTime()) and (startTime == aGeneralSchedule.getStartTime());
    }

bool GeneralSchedule::operator!=(const GeneralSchedule& aGeneralSchedule) const {
    return (endTime != aGeneralSchedule.getEndTime()) and (startTime != aGeneralSchedule.getStartTime());
    }

bool GeneralSchedule::operator>=(const GeneralSchedule& aGeneralSchedule) const {
    return (endTime >= aGeneralSchedule.getEndTime()) and (startTime >= aGeneralSchedule.getStartTime());
    }

bool GeneralSchedule::operator>(const GeneralSchedule& aGeneralSchedule) const {
    return (endTime > aGeneralSchedule.getEndTime()) and (startTime > aGeneralSchedule.getStartTime());
    }

bool GeneralSchedule::operator<=(const GeneralSchedule& aGeneralSchedule) const {
    return (endTime <= aGeneralSchedule.getEndTime()) and (startTime <= aGeneralSchedule.getStartTime());
    }

bool GeneralSchedule::operator<(const GeneralSchedule& aGeneralSchedule) const {
    return (endTime < aGeneralSchedule.getEndTime()) and (startTime < aGeneralSchedule.getStartTime());
    }


std::ostream& operator << (std::ostream& os, GeneralSchedule& aSchedule){
    os << aSchedule.startTime << std::endl;
    os << aSchedule.endTime;

    return os;
    }

std::istream& operator >> (std::istream& is, GeneralSchedule& aSchedule){
    is >> aSchedule.startTime;
    is >> aSchedule.endTime;

    return is;
    }

