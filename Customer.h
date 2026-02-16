#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <ostream>
#include "Date.h"

using namespace std;
using std::string;
enum CustomerCompareOptions {FullName, UserName, CustomerSince, DateOfBirth, CreditScore, HouseholdIncome, TotalSales};

/**
 * customer class
 */
class Customer {
private:
    string customer_id;
    string username;
    string first_name;
    string last_name;
    string street_address;
    string city;
    string state;
    string zip;
    string email;
    string gender;
    string company;
    string job_title;
    Date customer_since;
    string social_security_number;
    Date date_of_birth;
    int household_income;
    int credit_score;
    double total_sales;
    static CustomerCompareOptions compareWith;
public:
    /*
     * Default Customer Constructors
     */
    Customer();


    Customer(string customer_id, string username, string first_name, string last_name, string street_address, string city, string state, string zip, string email, string gender, string company, string job_title, Date customer_since, string social_security_number, Date date_of_birth, int household_income, int credit_score, double total_sales);
    /**
     * default constructor
     * @param record
     */
    Customer(string record);
    /**
     * sets value for the username
     * @param username
     */
    void setUserName(string username);
    /**
     * gets username
     * @return returns a string
     */
    string getUserName() const;
    /**
     * gets firstname
     * @return returns a string
     */
    string getFirstName() const;
    /**
     *  sets value for the firstname
     * @param first_name
     */
    void setFirstName(string first_name);
    /**
     * gets lastname
     * @return returns a string
     */
    string getLastName() const;
    /**
     * sets value for lastname
     * @param last_name
     */
    void setLastName(string last_name);
    /**
     * gets street address
     * @return returns a string
     */
    string getStreetAddress() const;
    /**
     * sets value for street address
     * @param street_address
     */
    void setStreetAddress(string street_address);
    /**
     * gets city
     * @return returns a string
     */
    string getCity() const;
    /**
     * set value for city
     * @param city
     */
    void setCity(string city);
    /**
     * gets state
     * @return returns a string
     */
    string getState() const;
    /**
     * sets value for state
     * @param state
     */
    void setState(string state);
    /**
     * gets zip
     * @return returns a string
     */
    string getZip() const;
    /**
     * sets value for zip
     * @param zip
     */
    void setZip(string zip);
    /**
     * gets email
     * @return returns a string
     */
    string getEmail() const;
    /**
     * sets value for email
     * @param email
     */
    void setEmail(string email);
    /**
     * gets gender
     * @return returns a string
     */
    string getGender() const;
    /**
     * sets value for gender
     * @param gender
     */
    void setGender(string gender);
    /**
     * gets company
     * @return returns a string
     */
    string getCompany() const;
    /**
     * sets value for company
     * @param company
     */
    void setCompany(string company);
    /**
     * gets job title
     * @return returns a string
     */
    string getJobTitle() const;
    /**
     * sets a value for job title
     * @param job_title
     */
    void setJobTitle(string job_title);
    /**
     * gets customer since
     * @return returns a string
     */
    Date getCustomerSince() const;
    /**
     * sets value for customer since
     * @param customer_since
     */
    void setCustomerSince(Date customer_since);
    /**
     * gets date of birth
     * @return returns date of birth
     */
    Date getDateOfBirth() const;
    /**
     * sets value for date of birth
     * @param date_of_birth
     */
    void setDateOfBirth(Date date_of_birth);
    /**
     * gets household income
     * @return returns household income
     */
    int getHouseholdIncome() const;
    /**
     * sets value for household income
     * @param household_income
     */
    void setHouseholdIncome(int household_income);
    /**
     * gets credit score
     * @return returns credit score
     */
    int getCreditScore() const;
    /**
     * sets value for credit score
     * @param credit_score
     */
    void setCreditScore(int credit_score);
    /**
     * gets total sales
     * @return returns credit score
     */
    double getTotalSales() const;
    /**
     * sets value for total sales
     * @param total_sales
     */
    void setTotalSales(double total_sales);
    /**
     * sets value for customer id
     * @param customer_id
     */
    void setCustomerID(string customer_id);
    /**
     * @purpose gets customers id
     * @return returns a string
     */
    string getCustomerID() const;
    /**
     * sets value for social security number
     * @param social_security_number
     */
    void setSocialSecurityNumber(string social_security_number);
    /**
     * @purpose gets social security number
     * @return returns a string
     */
    string getSocialSecurityNumber();


    string toString () const;
    static void setCompareWith(CustomerCompareOptions code);
    static CustomerCompareOptions getCompareWith();




    double getTotalSpent() {
        double total = 0.0;
        return total;
    }

    Date getOldest() {
        Date oldestDate;
        return oldestDate;
    }

    bool operator==(const Customer &lhs) const;
    bool operator!=(const Customer &lhs) const;
    bool operator<(const Customer &lhs) const;
    bool operator<=(const Customer &lhs) const;
    bool operator>(const Customer &lhs) const;
    bool operator>=(const Customer &lhs) const;

};

std::ostream & operator << (std::ostream &out, const Customer &customer);

#endif //CUSTOMER_H
