#include "Customer.h"
#include <sstream>

Customer::Customer() = default;

Customer::Customer(string customer_id, string username, string first_name, string last_name, string street_address, string city, string state, string zip, string email, string gender, string company, string job_title, Date customer_since, string social_security_number, Date date_of_birth, int household_income, int credit_score, double total_sales)
{
    this -> customer_id = customer_id;
    this -> username = username;
    this -> first_name = first_name;
    this -> last_name = last_name;
    this -> street_address = street_address;
    this -> city = city;
    this -> state = state;
    this -> zip = zip;
    this -> email = email;
    this -> gender = gender;
    this -> company = company;
    this -> job_title = job_title;
    this -> customer_since = customer_since;
    this -> social_security_number = social_security_number;
    this -> date_of_birth = date_of_birth;
    this -> household_income = household_income;
    this -> credit_score = credit_score;
    this -> total_sales = total_sales;
}

Customer::Customer(string record) {
    stringstream customer_info(record);
    string temp;
    getline(customer_info, temp, '\t');
    string delimiter = "\t";

    customer_id = temp;

    getline(customer_info, temp, '\t');
    username = temp;

    getline(customer_info, temp, '\t');
    first_name = temp;

    getline(customer_info, temp, '\t');
    last_name = temp;

    getline(customer_info, temp, '\t');
    street_address = temp;

    getline(customer_info, temp, '\t');
    city = temp;

    getline(customer_info, temp, '\t');
    state = temp;

    getline(customer_info, temp, '\t');
    zip = temp;

    getline(customer_info, temp, '\t');
    email = temp;

    getline(customer_info, temp, '\t');
    gender = temp;

    getline(customer_info, temp, '\t');
    company = temp;

    getline(customer_info, temp, '\t');
    job_title = temp;

    getline(customer_info, temp, '\t');
    customer_since = *(new Date(temp));

    getline(customer_info, temp, '\t');
    social_security_number = temp;

    getline(customer_info, temp, '\t');
    date_of_birth = *(new Date(temp));

    getline(customer_info, temp, '\t');
    household_income = stoi(temp);

    getline(customer_info, temp, '\t');
    credit_score = stoi(temp);

    getline(customer_info, temp, '\t');
    total_sales = stod(temp);

}

void Customer::setUserName(string username)
{
    this -> username = username;
}

string Customer::getUserName() const
{
    return username;
}
string Customer::getFirstName() const
{
    return first_name;
}
void Customer::setFirstName(string first_name)
{
    this -> first_name = first_name;
}

string Customer::getLastName() const
{
    return last_name;
}

void Customer::setLastName(string last_name)
{
    this -> last_name = last_name;
}

string Customer::getStreetAddress() const
{
    return street_address;
}

void Customer::setStreetAddress(string street_address)
{
    this -> street_address = street_address;
}

string Customer::getCity() const
{
    return city;
}

void Customer::setCity(string city)
{
    this -> city = city;
}

string Customer::getState() const
{
    return state;
}

void Customer::setState(string state)
{
    this -> state = state;
}

string Customer::getZip() const
{
    return zip;
}

void Customer::setZip(string zip)
{
    this -> zip = zip;
}

string Customer::getEmail() const
{
    return email;
}

void Customer::setEmail(string email)
{
    this -> email = email;
}

string Customer::getGender() const
{
    return gender;
}

void Customer::setGender(string gender)
{
    this -> gender = gender;
}

string Customer::getCompany() const
{
    return company;
}

void Customer::setCompany(string company)
{
    this -> company = company;
}

string Customer::getJobTitle() const
{
    return job_title;
}

void Customer::setJobTitle(string job_title)
{
    this -> job_title = job_title;
}

Date Customer::getCustomerSince() const
{
    return customer_since;
}

void Customer:: setCustomerSince(Date customer_since)
{
    this -> customer_since = customer_since;
}

Date Customer::getDateOfBirth() const
{
    return date_of_birth;
}

void Customer:: setDateOfBirth(Date date_of_birth)
{
    this -> date_of_birth = date_of_birth;
}

int Customer::getHouseholdIncome() const
{
    return household_income;
}

void Customer::setHouseholdIncome(int household_income)
{
    this -> household_income = household_income;
}

int Customer::getCreditScore() const
{
    return credit_score;
}

void Customer::setCreditScore(int credit_score)
{
    this -> credit_score = credit_score;
}

double Customer::getTotalSales() const
{
    return total_sales;
}

void Customer::setTotalSales(double total_sales)
{
    this -> total_sales = total_sales;
}

void Customer::setCustomerID(string customer_id)
{
    this -> customer_id = customer_id;
}

string Customer::getCustomerID() const
{
    return customer_id;
}

void Customer::setSocialSecurityNumber(string social_security_number)
{
    this -> social_security_number = social_security_number;
}

string Customer::getSocialSecurityNumber()
{
    return social_security_number;
}

//Stringify
string Customer::toString() const {
    string output = " ";
    output = (first_name) + " " + (last_name) + " " + "(" + (customer_id) + ")";
    return output;
}
CustomerCompareOptions Customer::compareWith;
//static
void Customer::setCompareWith(CustomerCompareOptions code){
    compareWith = code;
}

CustomerCompareOptions Customer::getCompareWith(){
    return compareWith;
}

//operator overloading

bool Customer::operator<(const Customer &lhs)
{
    switch (getCompareWith()) {
        case FullName:
        {
//            if (this->last_name < lhs.last_name) {return true;}
//             el\
//             se if (this->last_name > lhs.last_name) {return false;}
//             else if (this->first_name < lhs.first_name) { return true;}
//                return false;
            if (this->last_name < lhs.last_name || this->first_name < lhs.first_name)
            {
                return true;
            }
//            else if (this->last_name > lhs.last_name)
//            {
//                return false;
//            }
//            else if (this->first_name < lhs.first_name)
//            {
//                return true;
//            }
            else {
                return false;
            }
        }

        case UserName:
        {
//            if (this->username < lhs.username) {return true;}
//                else return false;
            if (this->username < lhs.username)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        case CustomerSince:
        {
//            if (this->customer_since < lhs.customer_since) {return true;}
//                else return false;
            if (this->customer_since < lhs.customer_since)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        case DateOfBirth:
        {
            if (this->date_of_birth < lhs.date_of_birth)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        case CreditScore:
        {
//            if (this->credit_score < lhs.credit_score) {return true;}
//            else return false;
            if (this->credit_score < lhs.credit_score)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        case HouseholdIncome:
        {
//            if (this->household_income < lhs.household_income) {return true;}
//                else return false;
            if (this->household_income < lhs.household_income)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        case TotalSales:
        {
//            if (this->total_sales < lhs.total_sales) {return true;}
//                else return false;
            if (this->total_sales < lhs.total_sales)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        default:
            return false;
    }
}

bool Customer::operator<=(const Customer &lhs) {
    return((*this < lhs) || (*this == lhs));
}
bool Customer::operator>(const Customer &lhs) {
    if (!(*this < lhs)) {
        return false;
    }
    else {
        return true;
    }
}
bool Customer::operator>=(const Customer &lhs) {
//    return ((*this < lhs) || (*this == lhs));
    if (!(*this <= lhs)) {
        return false;
    }
    else {
        return true;
    }

}

bool Customer::operator==(const Customer &lhs) {
    if (this->getCustomerID() != lhs.getCustomerID()) {return false;}
    return true;
}

bool Customer::operator!=(const Customer &lhs) {
    if (this->getCustomerID() == lhs.getCustomerID()) { return false;}
    return true;
}

//stream operator overloading,.

ostream &operator << (std::ostream &out, const Customer &customer) {
    out << customer.toString();
    return out;
}









