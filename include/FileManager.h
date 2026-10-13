#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include"Customer.h"
#include"Policy.h"
using namespace std;
class FileManager{
public:
    static void saveCustomer(Customer customer);
    static int getNextPolicyId();
    static void customerView(int mode);
    static void updateCustomer();
    static void deleteCustomer();
    static bool findId(int searchId,string &fileName,string indexPath);
    static int getNextCustomerId();
    static void savePolicy(Policy policy);
    static void policyView(int mode);
    static void updatePolicy();
    static void cancelPolicy();
    static void viewActivePolicies();

    static void makePayment();
    static void paymentHistory();
};

#endif
