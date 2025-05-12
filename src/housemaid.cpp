#include <iostream>
#include "/Users/artemka/С++ё/С++/Hotels_system/include/housemaid.hpp"
Housemaid::Housemaid(int id, std::string fname, std::string lname, std::string phone) : id(id), fname(fname), lname(lname), phone(phone){};

void Housemaid::showInfo() {
    std::cout << "Идентификатор горничной: " << id << std::endl;
    std::cout << "Имя: " << fname << std::endl;
    std::cout << "Фамилия: " << lname <<std::endl;
    std::cout << "Телефон: " << phone << std::endl;
}

std::string Housemaid::getName() {
    return fname + " " + lname;
}
