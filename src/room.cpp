#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/room.hpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/timerange.hpp"
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/src/timerange.cpp"
#include <iostream>

Room::Room(int id, std::string type) : id(id), type(type), cleaning(), reserved() {};

void Room::book(TimeRange period) {
    bool correctPeriod = true;
    for (int i = 0; i < reserved.size(); i++) {
        if (reserved[i].overlaps(period)) {
            std::cout << "Номер уже забронирован на выбранные даты";
            correctPeriod = false;
            break;
        }
    }
    if (correctPeriod){
        reserved.push_back(period);
    }
}

void Room::showInfo() {
    std::cout << "Номер комнаты: " << id << std::endl;
    std::cout << "Тип номера: " << type << std::endl;
    std::cout << "Номер забронирован на следующие даты:" << std::endl;
    for (int i = 0; i < reserved.size(); i++) {
        std::cout << i + 1 << "." << reserved[i].toString() << std::endl;
    }
    std::cout << std::endl << "Уборка в номере забронирована в следующие даты: " << std::endl;
    for (int i = 0; i < cleaning.size(); i++) {
        std::cout << cleaning[i].toString() << std::endl;
    }
}

void Room::checkIn() {
    if (isBusy) {
        std::cout << "В этом номере сейчас есть гости" << std::endl;
    }
    else {
        isBusy = true;
    }
}

void Room::addCleaning(DateTime clean) {
    cleaning.push_back(clean);
}

int main() {
    Room room(1, "Эконом");
    DateTime date1(1, 1, 2010);
    DateTime date2(5, 10, 2010);
    DateTime c(3, 7, 2010);
    TimeRange p1(date1, date2);
    room.book(p1);
    room.addCleaning(c);
    room.showInfo();
}