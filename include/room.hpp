#pragma once
#include <string>
#include "timedate.hpp"
#include "timerange.hpp"
#include <vector>

class Room {
    private:
        int id;
        bool isBusy = false;
        std::string type; //эконом, стандарт, люкс и прочее
        std::vector<DateTime> cleaning;
        std::vector<TimeRange> reserved;
    public:
        Room(int id, std::string type);
        void book(TimeRange period);
        void showInfo();
        void addCleaning(DateTime clean); // Добавить дату и время уборки
        void checkIn();
};