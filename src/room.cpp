#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/room.hpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/src/timerange.cpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/src/guest.cpp"
#include <iostream>

Room::Room(int id, int size, std::string type) : id(id), size(size), type(type), cleaning(), reservedDates(), guests(), reservedGuests(), recentVisitors(), recentVisits() {};

void Room::book(TimeRange period, Guest guest) {
    bool correctPeriod = true;
    for (int i = 0; i < reservedDates.size(); i++) {
        if (reservedDates[i].overlaps(period)) {
            std::cout << "Номер уже забронирован на выбранные даты";
            correctPeriod = false;
            break;
        }
    }
    if (correctPeriod){
        reservedDates.push_back(period);
        reservedGuests.push_back(guest);
    }
}

void Room::showInfo() {
    std::cout << "Номер комнаты: " << id << std::endl;
    std::cout << "Тип номера: " << type << std::endl;
    std::cout << "Максимальное количество гостей: " << size << std::endl;
    std::cout << "Номер забронирован на следующие даты на следующие имена:" << std::endl;
    for (int i = 0; i < reservedDates.size(); i++) {
        std::cout << reservedGuests[i].getName() <<std::endl;
        std::cout << i + 1 << "." << reservedDates[i].toString() << std::endl;
    }
    std::cout << std::endl << "Уборка в номере забронирована в следующие даты: " << std::endl;
    for (int i = 0; i < cleaning.size(); i++) {
        std::cout << cleaning[i].toString() << std::endl;
    }
    if (guests.size() == 0) {
        std::cout << "сейчас в номере нет гостей" << std::endl;
    }
    else {
        std::cout << "Сейчас в номере проживают: " << std::endl;
        for (int i = 0; i < guests.size(); i++){
            std::cout << i + 1 << ". " << guests[i].getName();
        }
    }
}

void Room::checkIn(Guest guest, TimeRange period) {
    if (guests.size() >= size) {
        std::cout << "В этом номере больше нет свободных мест для заселения" << std::endl;
    }
    else {
        guests.push_back(guest);
        recentVisitors.push_back(guest);
        recentVisits.push_back(period);
    }
}

void Room::checkOut(Guest guest) {
    if (guests.size() == 0) {
        std::cout << "Этот номер пока не занят" << std::endl;
    }
    else {
        guests.clear();
    }
}

void Room::addCleaning(DateTime clean) {
    cleaning.push_back(clean);
}

int main() {
    Room room(1, 2, "Эконом");
    DateTime date1(1, 1, 2010);
    DateTime date2(5, 10, 2010);
    DateTime date3(25, 4, 2015);
    DateTime date4(25, 5, 2015);
    DateTime c(3, 7, 2010);
    TimeRange p1(date1, date2);
    TimeRange p2(date3, date4);
    Guest guest(1, "Alex", "a", "@gmail.com", "3456789", 2345676, "20.04.1991", 50);
    room.book(p1, guest);
    room.addCleaning(c);
    room.showInfo();
    room.checkIn(guest, p2);
    room.showInfo();
    room.checkOut(guest);
    room.showInfo();
}