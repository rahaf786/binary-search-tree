#include "Date.h"
#include "Date.h"

Date::Date() {
    year = 1970;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day) {
    this -> year = year;
    this -> month = month;
    this -> day = day;

    if (!isValid(day, month, year)) {
        throw "Out of Range";
    }
}

Date::Date(string formatted_date) {
    string delimiter = "/";

    //find the position of the backslash
    // then grab the substring up to the position //
    // erase up to the position to be set up for the next value //
    int delimiter_position = formatted_date.find(delimiter,0);
    int month = stoi(formatted_date.substr(0,delimiter_position));
    formatted_date.erase(0, delimiter_position + delimiter.length());

    delimiter_position = formatted_date.find(delimiter, 0);
    int day = stoi(formatted_date.substr(0, delimiter_position));
    formatted_date.erase(0, delimiter_position + delimiter.length());

    int year = stoi(formatted_date);

    if (!isValid(day, month, year)) {
        throw "Out of Range";
    }

    setDate(year, month, day);
}

void Date::setDate(int year, int month, int day) {
    this -> year = year;
    this -> month = month;
    this -> day = day;

    if (!isValid(day, month, year)) {
        throw "Out of Range";
    }
}
int Date::getYear() const {
    return this -> year;
}

int Date::getMonth() const {
    return  month;
}

int Date::getDay() const {
    return day;
}

string Date::toString() const {
    string output = "";
    output = to_string(getMonth()) + "/" + to_string(getDay()) + "/" + to_string(getYear());
    return output;

}

//operator overloading

bool Date::operator==(const Date &lhs) {
    if (this->getYear() != lhs.getYear()) {return false;}
    if (this->getMonth() != lhs.getMonth()) {return false;}
    if (this->getDay() != lhs.getDay()) {return false;}
    return true;
}
bool Date::operator!=(const Date &lhs) {
    return !(*this == lhs);
}

bool Date::operator<(const Date &lhs) {
    if (this -> year < lhs.year){
        return true;
    }else if (this->year > lhs.year){
        return false;
    } else{
        if (this -> month < lhs.month){
            return true;
        }else { //same month and same year
            if (this ->day < lhs.day) {
            return true;
            }else {//same or greater
                return false;
            }
        }
    }
}

bool Date::operator<=(const Date &lhs) {
    return((*this < lhs) || (*this == lhs));
}
bool Date::operator>(const Date &lhs) {
    return !(*this <= lhs);
}
bool Date::operator>=(const Date &lhs) {
    return (*this < lhs);
}

ostream &operator<< (ostream &out, const Date &date){
    out << date.toString();
    return out;
}

int Date::daysInAMonth(int month, int year) {
    int days;
    switch (month) {
        case 2:
            if (year % 400 == 0) days = 29;
            else if (year % 100 == 0) days = 28;
            else if (year % 4 == 0) days = 29;
            else days = 28;

            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
    }
    return days;
}

bool Date::isValid(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > daysInAMonth(month, year)){
        return false;
    }
    return true;
}





