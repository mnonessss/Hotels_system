#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/timerange.hpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/timedate.hpp"
#include "timedate.cpp"
#include <iostream>
TimeRange::TimeRange(DateTime start, DateTime finish) {
    this->start = start;
    this->finish = finish;
}

bool TimeRange::overlaps(TimeRange other) {
    if (other.start.getSeconds() > this->finish.getSeconds()) {
        return false;
    }
    else if (other.finish.getSeconds() < this->start.getSeconds()) {
        return false;
    }
    else {
        return true;
    }
}

std::string TimeRange::toString() {
    std::string res = "Начало промежутка: " + start.toString() + ";\nКонец промежутка: " + finish.toString();
    return res;
}

