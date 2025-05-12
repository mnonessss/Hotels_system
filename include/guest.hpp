//pms - property management system
//класс при запуске main не будет занимать память, память выделится только пр создании экземпляра класса
//struct - по сути тот же класс, но в нем по умлочанию выставлены public
#pragma once
#include <string>
#include <vector>
#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/timerange.hpp"

//Если не напишем public или private, то по умолчанию выставляется private
class Guest {
    private: //модификатор доступа
        signed long int id;
        std::string firstName; //свойство или поле класса
        std::string lastName;
        std::string phoneNumber;
        unsigned long int passNumber;
        std::string email;
        std::string date;
        unsigned long int loyaltyPoints;
    public:
        Guest(signed long int id, 
            std::string firstName,
            std::string lastName,
            std::string email,
            std::string phoneNumber,
            unsigned long int passNumber,
            std::string date, 
            unsigned long int loyaltyPoints); //это конструктор, слева от него ничего не пишем
        void setFirstName(std::string);
        void setLastName(std::string);
        void addPhoneNumber(std::string);
        void addPassportNumber(unsigned long int);
        void setEmail(std::string);
        std::string getName();
        void showInfo();
};



