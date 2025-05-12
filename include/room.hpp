#pragma once
#include <string>
#include "timedate.hpp"
#include "timerange.hpp"
#include "guest.hpp"
#include <vector>

class Room {
    private:
        int id;
        int size; // максимальное количество персон
        std::vector<Guest> guests;
        std::string type; //эконом, стандарт, люкс и прочее
        std::vector<DateTime> cleaning;
        std::vector<TimeRange> reservedDates;
        std::vector<Guest> reservedGuests;
        std::vector<TimeRange> recentVisits;
        std::vector<Guest> recentVisitors;

    public:
        Room(int id, int size, std::string type);
        void book(TimeRange period, Guest guest);
        void showInfo();
        void addCleaning(DateTime clean); // Добавить дату и время уборки
        void checkIn(Guest guest, TimeRange period);
        void checkOut(Guest guest);
};