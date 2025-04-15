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

int main(){
    DateTime date1(1, 1, 1995);
    DateTime date2(9, 4, 2030);
    TimeRange tr1(date1, date2);
    DateTime date3(1, 1, 2030);
    DateTime date4(9, 4, 2050);
    TimeRange tr2(date3, date4);
    // if (tr1.overlaps(tr2)) {
    //     std::cout << "Перекрывает" << std::endl;
    // }
    // else {
    //     std::cout << "Not" << std::endl;
    // }
    // return 0;
    std::cout << tr1.toString() << std::endl;
}