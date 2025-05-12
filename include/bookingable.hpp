#pragma once
#include <string>
#include "timerange.hpp"
#include "guest.hpp"
#include <vector>

class BookingAble {
    protected:
        signed long int id;
        std::string name;
        std::vector<Guest> reservedGuests;
        std::vector<TimeRange> reservedTimes;
    public:
        BookingAble(signed long int id, std::string name);
        void book(Guest guest, TimeRange period);
        void showInfo();
};