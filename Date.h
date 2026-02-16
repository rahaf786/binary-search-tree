#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

using namespace std;
/**
 * Represent a calender date with a month, date and year
 */
class Date {
private:
    int year;
    int month;
    int day;
public:
    /**
     * Default date constructor
     */
    Date();
    /**
     * Constructor that takes a year, month and day
     * @param year the date's year as a number
     * @param month the date's month as a number between 1 and 12
     * @param day the date's day as a number
     */
    Date(int year, int month, int day);

    Date(string formatted_date);

    /**
     * Changes the date
     * @param year the date's year as a number
     * @param month the date's month as a number between 1 and 12
     * @param day the date's day as a number
     */
    void setDate(int year, int month, int day);
    /**
     * @return the date's year as a number
     */
    int getYear() const;
    /*
     * @return the date's month as a number
     */
    int getMonth() const;
    /*
     *
     * @return the date's day of the month as a number
     */
    int getDay() const;
    /*
     * @return formatted representation of the date (m/d/y)
     */
    string toString() const;
    /*
     * operator overloading
     */

    bool operator==(const Date &lhs) const;
    bool operator!=(const Date &lhs) const;

    bool operator < (const Date & lhs) const;
    bool operator <=(const Date & lhs) const;
    bool operator > (const Date &lhs) const;
    bool operator >= (const Date &lhs) const;

private: // internal helper functions (can also be up in the 1st private class)
    int daysInAMonth(int month, int year);
    bool isValid(int day, int month, int year);
};

ostream &operator<< (ostream &out, const Date &date);

#endif //DATE_H
