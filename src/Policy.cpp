#include<iostream>
#include"../include/Policy.h"
#include"../include/FileManager.h"
#include<stack>
using namespace std;

Policy::Policy(int id){
    policyId=id;
    duration=12;
    paymentStatus="Pending";
    paidAmount=0;
    renewalCount=0;
}

inline bool back(string input,int& currentStep,stack<int>& stepHistory){
    if(input=="B"||input=="b"){
        currentStep=stepHistory.top();
        stepHistory.pop();
        return true;
    }
    return false;
}

bool Policy::input(){
    stack<int>stepHistory;
    int currentStep=1;
    string tempInput;
    while(currentStep<=8){
        switch(currentStep){
            case 1:
                cout<<"Enter Customer ID (or 'B' to exit): ";
                cin>>tempInput;
                if(tempInput=="B"||tempInput=="b"){return false;}
                customerId=stoi(tempInput);
                {
                    string fileName;
                    if(FileManager::findId(customerId,fileName,"data/customers/customer_index.txt")){
                        stepHistory.push(currentStep);
                        currentStep=2;
                    }
                    else{
                        cout<<"Customer ID not found!"<<endl;
                    }
                }
                break;
case 2:
            {
                cout<<"1. Life Insurance\n2. Health Insurance\n3. Vehicle Insurance\n4. Property Insurance\nEnter Type (or 'B' to go back): ";
                cin>>tempInput;
                if(back(tempInput,currentStep,stepHistory)){break;}

                int choice=stoi(tempInput);
                if(choice==1){
                    insuranceType="Life";
                    stepHistory.push(currentStep);
                    currentStep=3;
                }
                else if(choice==2){
                    insuranceType="Health";
                    stepHistory.push(currentStep);
                    currentStep=3;
                }
                else if(choice==3){
                    insuranceType="Vehicle";
                    stepHistory.push(currentStep);
                    currentStep=4;
                }
                else if(choice==4){
                    insuranceType="Property";
                    stepHistory.push(currentStep);
                    currentStep=5;
                }
                else{
                    cout<<"Invalid Type!"<<endl;
                }
                break;
            }
            case 3:
                cout<<"Enter Age (or 'B' to go back): ";
                cin>>tempInput;
                if(back(tempInput,currentStep,stepHistory)){break;}
                age=stoi(tempInput);
                cout<<"Enter Coverage Amount: ";
                cin>>coverageAmount;
                stepHistory.push(currentStep);
                currentStep=6;
                break;
            case 4:
                cout<<"Enter Vehicle Value (or 'B' to go back): ";
                cin>>tempInput;
                if(back(tempInput,currentStep,stepHistory)){break;}
                vehicleValue=stod(tempInput);
                cout<<"Enter Vehicle Type: ";
                cin>>vehicleType;
                stepHistory.push(currentStep);
                currentStep=6;
                break;
            case 5:
                cout<<"Enter Property Value (or 'B' to go back): ";
                cin>>tempInput;
                if(back(tempInput,currentStep,stepHistory)){break;}
                propertyValue=stod(tempInput);
                stepHistory.push(currentStep);
                currentStep=6;
                break;
            case 6:
                cout<<"Enter Duration in Months (or 'B' to go back): ";
                cin>>tempInput;
                if(back(tempInput,currentStep,stepHistory)){break;}
                duration=stoi(tempInput);
                if(duration<=0){
                    cout<<"Must be greater than 0!"<<endl;
                }
                else{
                    stepHistory.push(currentStep);
                    currentStep=7;
                }
                break;
            case 7:
                cout<<"Enter Start Date (or 'B' to go back): ";
                cin>>ws;
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                startDate=tempInput;
                stepHistory.push(currentStep);
                currentStep=8;
                break;
            case 8:
                cout<<"Enter End Date (or 'B' to go back): ";
                getline(cin,tempInput);
                if(back(tempInput,currentStep,stepHistory)){break;}
                endDate=tempInput;
                premium=calculatePremium();
                status="Active";
                currentStep=9;
                break;
        }
    }
    return true;
}

double Policy::calculatePremium(){
    double premium=0;
    double years=duration/12.0;
    if(insuranceType=="Life"){
        premium=coverageAmount*0.02*years;
    }
    else if(insuranceType=="Health"){
        premium=coverageAmount*0.03*years;
    }
    else if(insuranceType=="Vehicle"){
        premium=vehicleValue*0.025*years;
    }
    else if(insuranceType=="Property"){
        premium=propertyValue*0.01*years;
    }
    return premium;
}

void Policy::display(){
    cout<<"Policy ID: "<<policyId<<endl;
    cout<<"Customer ID: "<<customerId<<endl;
    cout<<"Insurance Type: "<<insuranceType<<endl;
    cout<<"Premium: "<<premium<<endl;
    cout<<"Start Date: "<<startDate<<endl;
    cout<<"End Date: "<<endDate<<endl;
    cout<<"Status: "<<status<<endl;
}

int Policy::getPolicyId(){return policyId;}

int Policy::getCustomerId(){return customerId;}

string Policy::getInsuranceType(){return insuranceType;}

double Policy::getPremium(){return premium;}

string Policy::getStartDate(){return startDate;}

string Policy::getEndDate(){return endDate;}

string Policy::getStatus(){return status;}

int Policy::getAge(){return age;}

double Policy::getCoverageAmount(){return coverageAmount;}

double Policy::getVehicleValue(){return vehicleValue;}

double Policy::getPropertyValue(){return propertyValue;}

string Policy::getVehicleType(){return vehicleType;}

int Policy::getDuration(){return duration;}

string Policy::getPaymentStatus(){return paymentStatus;}

double Policy::getPaidAmount(){return paidAmount;}

int Policy::getRenewalCount(){return renewalCount;}
