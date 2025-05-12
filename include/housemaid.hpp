#pragma once
#include <string>
#include <vector>

class Housemaid {
    private:
        int id;
        std::string fname;
        std::string lname;
        std::string phone;
    public:
        Housemaid(int id, std::string fname, std::string lname, std::string phone);
        void showInfo();
        std::string getName();
};
