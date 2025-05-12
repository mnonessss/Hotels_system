#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/guest.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

void Guest::setFirstName(std::string name) {
    //делаем какие - то проверки
    firstName = name;
}

void Guest::setLastName(std::string lname) {
    lastName = lname;
}

void Guest::addPhoneNumber(std::string number) {
    phoneNumber = number;
}

void Guest::addPassportNumber(unsigned long int passport) {
    passNumber = passport;
}

void Guest::setEmail(std::string email) {
    this->email = email;
}

std::string Guest::getName() {
    std::string str = firstName + " " + lastName + "\n";
    return str;
}

Guest::Guest(signed long int id, 
    std::string firstName,
    std::string lastName,
    std::string email,
    std::string phoneNumber,
    unsigned long int passNumber,
    std::string date, 
    unsigned long int loyaltyPoints) {
        this->id = id;
        this->passNumber = passNumber;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->date = date;
        this->loyaltyPoints = loyaltyPoints;
}

void Guest::showInfo() {
    std::cout << "Идентификатор: " << this->id << std::endl;
    std::cout << "Имя: " << this->firstName << std::endl;
    std::cout << "Фамилия: " << this->lastName << std::endl;
    std::cout << "Номер паспорта: " << this->passNumber << std::endl;
    std::cout << "Электронная почта: " << this->email << std::endl;
    std::cout << "Телефон: " << this->phoneNumber << std::endl;
    std::cout << "Дата: " << this->date << std::endl;
    std::cout << "Бонусные баллы: " << this->loyaltyPoints << std::endl;
    std::cout << std::endl << std::endl;
}

std::vector<Guest> loadGuests(std::string filename) {
    std::vector<Guest> guests;
    std::ifstream file(filename); //создаем файловый поток на чтение
    std::string line; //сюда построково будем считывать содержимое файла
    std::getline(file, line); //читает строку до перехода на новую строку
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        char delim;
        unsigned long int id;
        std::string fname;
        std::string lname;
        std::string phoneNumber;
        std::string email;
        std::string date;
        unsigned long int passport;
        unsigned long int loyaltyPoints;
        ss >> id >> delim;
        std::getline(ss, fname, ',');
        std::getline(ss, lname, ',');
        std::getline(ss, email, ',');
        std::getline(ss, phoneNumber, ',');
        ss >> passport >> delim;
        std::getline(ss, date, ',');
        ss >> loyaltyPoints;
        Guest guest(
            id,
            fname,
            lname, 
            email, 
            phoneNumber, 
            passport, 
            date, 
            loyaltyPoints);
        guests.push_back(guest);
    };
    return guests;
}


