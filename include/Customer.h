#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int customerId;
    std::string name;
    int age;
    std::string gender;
    std::string phone;
    std::string email;
    std::string address;

public:
    Customer(int id);
    bool input();
    void display();

    int getAge();
    std::string getName();
    std::string getGender();
    std::string getPhone();
    std::string getEmail();
    std::string getAddress();
    int getCustomerId();
};

#endif
