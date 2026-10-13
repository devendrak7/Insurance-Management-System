#ifndef POLICY_H
#define POLICY_H

#include <string>

class Policy {
private:
    int policyId;
    int customerId;
    std::string insuranceType;
    double premium;
    std::string startDate;
    std::string endDate;
    std::string status;
    int age;
    double coverageAmount;
    double vehicleValue;
    double propertyValue;
    std::string vehicleType;
    int duration;
    std::string paymentStatus;
    double paidAmount;
    int renewalCount;

public:
    Policy(int id);
    bool input();
    void display();

    int getPolicyId();
    int getCustomerId();
    std::string getInsuranceType();
    double getPremium();
    std::string getStartDate();
    std::string getEndDate();
    std::string getStatus();
    double calculatePremium();
    int getAge();
    double getCoverageAmount();
    double getVehicleValue();
    double getPropertyValue();
    std::string getVehicleType();
    int getDuration();
    std::string getPaymentStatus();
    double getPaidAmount();
    int getRenewalCount();
};

#endif
