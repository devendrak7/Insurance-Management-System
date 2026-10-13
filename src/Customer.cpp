#include<iostream>
#include"../include/Customer.h"
#include<stack>
using namespace std;

Customer::Customer(int id){
    customerId=id;
}

inline bool back(string input,int& currentStep,stack<int>& stepHistory){
    if(input=="B"||input=="b"){
        currentStep=stepHistory.top();
        stepHistory.pop();
        return true;
    }
    return false;
}

bool Customer::input(){
    stack<int>stepHistory;
    int currentStep=1;
    string tempInput;
    cin.ignore();
    while(currentStep<=6){
        switch(currentStep){
            case 1:
                cout<<"Enter Name (or 'B' to exit): ";
                getline(cin,tempInput);
                if(tempInput=="B"||tempInput=="b"){return false;}
                name=tempInput;
                stepHistory.push(currentStep);
                currentStep++;
                break;
            case 2:
                cout<<"Enter Age (or 'B' to go back): ";
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                age=stoi(tempInput);
                stepHistory.push(currentStep);
                currentStep++;
                break;
            case 3:
                cout<<"Enter Gender (or 'B' to go back): ";
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                gender=tempInput;
                stepHistory.push(currentStep);
                currentStep++;
                break;
            case 4:
                cout<<"Enter Phone (or 'B' to go back): ";
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                phone=tempInput;
                stepHistory.push(currentStep);
                currentStep++;
                break;
            case 5:
                cout<<"Enter Email (or 'B' to go back): ";
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                email=tempInput;
                stepHistory.push(currentStep);
                currentStep++;
                break;
            case 6:
                cout<<"Enter Address (or 'B' to go back): ";
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                address=tempInput;
                stepHistory.push(currentStep);
                currentStep++;
                break;
        }
    }
    return true;
}

void Customer::display(){
    cout<<"Customer ID: "<<customerId<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"Phone: "<<phone<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Address: "<<address<<endl;
}

int Customer::getCustomerId(){return customerId;}

int Customer::getAge(){return age;}

string Customer::getName(){return name;}

string Customer::getGender(){return gender;}

string Customer::getPhone(){return phone;}

string Customer::getEmail(){return email;}

string Customer::getAddress(){return address;}
