#include "timedate.hpp"
#include <string>
#pragma once

class TimeRange{
    private:
        DateTime start;
        DateTime finish;
    public:
        TimeRange(DateTime start, DateTime finish);
        bool overlaps(TimeRange other);
        std::string toString();
};