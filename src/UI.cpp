#include<iostream>
#include<cstdlib>
#include<string>
#include"../include/UI.h"
#include"../include/Customer.h"
#include"../include/FileManager.h"
using namespace std;

void clearScreen(){system("cls");}
void pauseScreen(){
    cout<<"Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void header(string title){
    clearScreen();
    cout<<endl;
    cout<<"=============================================================="<<endl;
    cout<<"              INSURANCE MANAGEMENT SYSTEM"<<endl;
    cout<<"=============================================================="<<endl;
    cout<<"                    "<<title<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
}

void customerMenu(){
    while(true)
    {
        header("CUSTOMER MANAGEMENT");
        cout<<endl;
        cout<<"1. Add Customer"<<endl;
        cout<<"2. Update Customer"<<endl;
        cout<<"3. View Customer"<<endl;
        cout<<"4. Delete Customer"<<endl;
        cout<<"5. Search All Customers"<<endl;
        cout<<"B  Back"<<endl;
        cout<<"0  Exit"<<endl;
        cout<<"Enter your choice: ";

        char choice;
        cin>>choice;
        switch(choice){
            case '1':{
                header("ADD CUSTOMER");
                Customer customer(FileManager::getNextCustomerId());
                if(customer.input()){
                    customer.display();
                    FileManager::saveCustomer(customer);
                }
                pauseScreen();
                break;
            }
            case '2':
                header("UPDATE CUSTOMER");
                FileManager::updateCustomer();
                pauseScreen();
                break;
            case '3':{
                header("VIEW ALL CUSTOMER");
                FileManager::customerView(1);
                pauseScreen();
                break;
            }
            case '4':
                header("DELETE CUSTOMER");
                FileManager::deleteCustomer();
                pauseScreen();
                break;
            case '5':{
                header("VIEW CUSTOMERS");
                FileManager::customerView(2);
                pauseScreen();
                break;
            }
            case 'B':
            case 'b':
                return;

            case '0':
                exit(0);
            default:
                cout<<"Invalid choice!"<<endl;
                pauseScreen();
        }
    }
}

void policyMenu(){
    while(true){
        cout<<"1. Create Policy"<<endl;
        cout<<"2. View All Policies"<<endl;
        cout<<"3. Search Policy"<<endl;
        cout<<"4. Update Policy"<<endl;
        cout<<"5. Cancel Policy"<<endl;
        cout<<"6. View Active Policies"<<endl;
        cout<<"B. Back"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";

        char choice;
        cin>>choice;
        switch(choice){
case '1':{
                header("CREATE POLICY");
                Policy policy(FileManager::getNextPolicyId());
                if(policy.input()){
                    policy.display();
                    FileManager::savePolicy(policy);
                }
                pauseScreen();
                break;
            }

            case '2':
                header("VIEW ALL POLICIES");
                FileManager::policyView(1);
                pauseScreen();
                break;

            case '3':
                header("VIEW POLICY");
                FileManager::policyView(2);
                pauseScreen();
                break;

            case '4':
                header("UPDATE POLICY");
                FileManager::updatePolicy();
                pauseScreen();
                break;

            case '5':
                header("CANCEL POLICY");
                FileManager::cancelPolicy();
                pauseScreen();
                break;

            case '6':
                header("ACTIVE POLICIES");
                FileManager::viewActivePolicies();
                pauseScreen();
                break;

            case 'B':
            case 'b':
                return;

            case '0':
                exit(0);

            default:
                cout<<endl;
                cout<<"Invalid choice!"<<endl;
                pauseScreen();
        }
    }
}

void paymentMenu(){
    while(true){
        header("PAYMENT MANAGEMENT");

        cout<<"1. Make Payment"<<endl;
        cout<<"2. Payment History"<<endl;
        cout<<"B. Back"<<endl;
        cout<<"M. Main Menu"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";

        char choice;
        cin>>choice;

        switch(choice){
        case '1':
            header("MAKE PAYMENT");
            FileManager::makePayment();
            pauseScreen();
            break;
        case '2':
            header("PAYMENT HISTORY");
            FileManager::paymentHistory();
            pauseScreen();
            break;
        case 'B':
        case 'b':
            return;
        case 'M':
        case 'm':
            mainMenu();
            return;
        case '0':
            exit(0);
        default:
            cout<<"Invalid choice!"<<endl;
            pauseScreen();
        }
    }
}

void mainMenu(){
    while(true){
        header("MAIN MENU");
        cout<<"1. Customer Management"<<endl;
        cout<<"2. Policy Management"<<endl;
        cout<<"3. Payment Management"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";

        char choice;
        cin>>choice;

        switch(choice){
        case '1':
            customerMenu();
            break;
        case '2':
            policyMenu();
            break;
        case '3':
            paymentMenu();
            break;
        case '0':
            clearScreen();
            cout<<"Thank you for using Insurance Management System."<<endl;
            exit(0);
        default:
            cout<<"Invalid choice!"<<endl;
            pauseScreen();
        }
    }
}
