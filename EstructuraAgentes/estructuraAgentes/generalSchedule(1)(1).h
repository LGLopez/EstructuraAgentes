#ifndef GENERALSCHEDULE_H_INCLUDED
#define GENERALSCHEDULE_H_INCLUDED

#include "time.h"

class GeneralSchedule{
private:
    Time startTime;
    Time endTime;

public:
    GeneralSchedule();

    Time getStartTime();
    Time getEndTime();

    std::string toString();

    void setStartTime(Time);
    void setEndTime(Time);


};





#endif // GENERALSCHEDULE_H_INCLUDED
