#include <iostream>
#include"/home/mnones/Рабочий стол/конспекты сириус/С++/include/bookingable.hpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/src/timerange.cpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/src/guest.cpp"


BookingAble::BookingAble(signed long int id = 0, std::string name = ""): id(id), name(name), reservedGuests(), reservedTimes() {};

void BookingAble::book(Guest guest, TimeRange period) {
    bool correctPeriod = true;
    for (int i = 0; i < reservedTimes.size(); i++) {
        if (reservedTimes[i].overlaps(period)) {
            std::cout << "Номер уже забронирован на выбранные даты";
            correctPeriod = false;
            break;
        }
    }
    if (correctPeriod){
        reservedTimes.push_back(period);
        reservedGuests.push_back(guest);
    }
}

void BookingAble::showInfo() {
    std::cout << "Идентификатор: " << id << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "История бронирований: " << std::endl;
    if (reservedGuests.size() == 0) {
        std::cout << "Бронирований пока не было" << std::endl;
    }
    else {
        for (int i = 0; i < reservedGuests.size(); i++) {
            std::cout << i + 1 << ". " << reservedGuests[i].getName() << std::endl;
            std::cout << reservedTimes[i].toString() << std::endl;
        }
    }
}

int main() {
    BookingAble b(1, "lalalala");
    Guest guest(1, "Alex", "a", "@gmail.com", "3456789", 2345676, "20.04.1991", 50);
    DateTime date1(1, 1, 2010);
    DateTime date2(5, 10, 2010);
    TimeRange p1(date1, date2);
    b.book(guest, p1);
    b.showInfo();
}