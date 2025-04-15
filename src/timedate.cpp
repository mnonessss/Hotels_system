#include "/home/mnones/Рабочий стол/конспекты сириус/С++/include/timedate.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//в include все хедеры, в src - cpp файлы, include должен быть внутри src


DateTime::DateTime(int days, int months, int years, int hours, int minutes, int seconds) {
    this->seconds = 31536000 * (years - 1970) + 2592000 * (months - 1) + 86400 * (days - 1) + 3600 * hours + minutes * 60 + seconds;
}

DateTime::DateTime(int64 sec) : seconds(sec){ //список инициализации, он сразу инициализирует значение, это быстрее, чем по классике
}

std::string DateTime::toString() {
    int64 tempSeconds = seconds;
    int64 years = 1970 + (tempSeconds / 31536000);
    tempSeconds %= 31536000;
    int64 months = 1 + tempSeconds / 2592000;
    tempSeconds %= 2592000;
    int64 days = 1 + tempSeconds / 86400;
    tempSeconds %= 86400;
    int64 hours = tempSeconds / 3600;
    tempSeconds %= 3600;
    int64 minutes = tempSeconds / 60;
    tempSeconds %= 60;
    int64 seconds = tempSeconds;
    char str[60];
    snprintf(str, 60, "%02lld-%02lld-%04lld %02lld:%02lld:%02lld", days, months, years, hours, minutes, seconds);
    return std::string(str);
}

int DateTime::getSeconds(){
    return seconds;
}

int main2() {
    DateTime date1(1, 1, 1970);
    DateTime date2(9, 4, 2025);
    std::string str = date2.toString();
    std::cout << str << std::endl;
    return 0;
}