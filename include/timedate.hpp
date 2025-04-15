#include <string>
#pragma once
typedef unsigned long long int64;

class DateTime {
    private:
        int64 seconds;
    public:
        std::string toString();
        int getSeconds();
        DateTime(int days, 
            int months,
            int years, 
            int hours=0,
            int minutes=0,
            int seconds=0);
        DateTime(int64 sec=0);
        
};