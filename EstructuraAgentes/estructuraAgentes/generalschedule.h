#ifndef GENERALSCHEDULE_H_INCLUDED
#define GENERALSCHEDULE_H_INCLUDED

#include "time.h"

class GeneralSchedule{
private:
    Time startTime;
    Time endTime;

public:
    GeneralSchedule();
    GeneralSchedule(const Time&, const Time&);
    GeneralSchedule(const GeneralSchedule&);

    GeneralSchedule& operator = (const GeneralSchedule&);

    Time getStartTime() const;
    Time getEndTime() const;

    std::string toString() const;

    void setStartTime(const Time&);
    void setEndTime(const Time&);

    bool operator == (const GeneralSchedule&) const;
    bool operator != (const GeneralSchedule&) const;
    bool operator >= (const GeneralSchedule&) const;
    bool operator >  (const GeneralSchedule&) const;
    bool operator <= (const GeneralSchedule&) const;
    bool operator <  (const GeneralSchedule&) const;

    friend std::ostream& operator << (std::ostream&, GeneralSchedule&);
    friend std::istream& operator >> (std::istream&, GeneralSchedule&);

};


#endif // GENERALSCHEDULE_H_INCLUDED
