#include<iostream>
#include<fstream>
#include<string>
#include"../include/FileManager.h"
#include"../include/Customer.h"
using namespace std;

int FileManager::getNextPolicyId(){
    ifstream indexFile("data/policies/policy_index.txt");
    string fileName;
    int maxId=999;

    while(getline(indexFile,fileName)){
        int pos=fileName.find('_');
        int id=stoi(fileName.substr(0,pos));

        if(id>maxId){
            maxId=id;
        }
    }
    indexFile.close();
    return maxId+1;
}

void FileManager::saveCustomer(Customer customer){
    string fileName=to_string(customer.getCustomerId())+"_"+customer.getName()+".txt";
    string path="data/customers/"+fileName;

    ofstream file(path);

    file<<customer.getCustomerId()<<endl;
    file<<customer.getName()<<endl;
    file<<customer.getAge()<<endl;
    file<<customer.getGender()<<endl;
    file<<customer.getPhone()<<endl;
    file<<customer.getEmail()<<endl;
    file<<customer.getAddress()<<endl;

    file.close();

    ofstream indexFile("data/customers/customer_index.txt",ios::app);
    indexFile<<fileName<<endl;
    indexFile.close();
}

void FileManager::customerView(int mode){
    ifstream indexFile("data/customers/customer_index.txt");
    string fileName;

    int searchId=0;

    if(mode==2){
        cout<<"Enter Customer ID: ";
        cin>>searchId;
    }

    int found=0;

    while(getline(indexFile,fileName)){
        int pos=fileName.find('_');
        string idString=fileName.substr(0,pos);
        int id=stoi(idString);

        if(mode==2&&id!=searchId){
            continue;
        }

        string path="data/customers/"+fileName;
        ifstream file(path);

        int Id,age;
        string name,gender,phone,email,address;

        file>>Id;
        file.ignore();
        getline(file,name);
        file>>age;
        file.ignore();
        getline(file,gender);
        getline(file,phone);
        getline(file,email);
        getline(file,address);

        cout<<"Customer ID: "<<Id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Phone: "<<phone<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"-----------------------------"<<endl;

        file.close();
        found=1;

        if(mode==2){
            break;
        }
    }

    if(!found){
        if(mode==2){
            cout<<"Customer not found!"<<endl;
        }
        else{
            cout<<"No Customers Found!"<<endl;
        }
    }

    indexFile.close();
}

void FileManager::updateCustomer(){
    ifstream indexFile("data/customers/customer_index.txt");
    string fileName;
    int searchId;

    cout<<"Enter ID : ";
    cin>>searchId;
    int notFound= 1;
    while(getline(indexFile,fileName)){
        int pos= fileName.find("_");
        string idstr= fileName.substr(0,pos);
        int id = stoi(idstr);
        if(id ==searchId){
            string path="data/customers/"+fileName;
            ifstream file(path);

            int Id,age;
            string name,gender,phone,email,address;
            file>>Id;
            file.ignore();
            getline(file,name);
            file>>age;
            file.ignore();
            getline(file,gender);
            getline(file,phone);
            getline(file,email);
            getline(file,address);
            int choice;

            cout<<"1. Update Name"<<endl;
            cout<<"2. Update Age"<<endl;
            cout<<"3. Update Gender"<<endl;
            cout<<"4. Update Phone"<<endl;
            cout<<"5. Update Email"<<endl;
            cout<<"6. Update Address"<<endl;
            cout<<"7. Update All"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
            cin.ignore();

            switch(choice){
            case 1:
                cout<<"Enter New Name: ";
                getline(cin,name);
                break;

            case 2:
                cout<<"Enter New Age: ";
                cin>>age;
                break;

            case 3:
                cout<<"Enter New Gender: ";
                getline(cin,gender);
                break;

            case 4:
                cout<<"Enter New Phone: ";
                getline(cin,phone);
                break;

            case 5:
                cout<<"Enter New Email: ";
                getline(cin,email);
                break;

            case 6:
                cout<<"Enter New Address: ";
                getline(cin,address);
                break;

            case 7:
                cout<<"Enter New Name: ";
                getline(cin,name);
                cout<<"Enter New Age: ";
                cin>>age;
                cin.ignore();
                cout<<"Enter New Gender: ";
                getline(cin,gender);
                cout<<"Enter New Phone: ";
                getline(cin,phone);
                cout<<"Enter New Email: ";
                getline(cin,email);
                cout<<"Enter New Address: ";
                getline(cin,address);
                break;
            default:
                cout<<"Invalid choice!"<<endl;
            }
            ofstream outfile(path);

            outfile<<Id<<endl;
            outfile<<name<<endl;
            outfile<<age<<endl;
            outfile<<gender<<endl;
            outfile<<phone<<endl;
            outfile<<email<<endl;
            outfile<<address<<endl;
            outfile.close();
            cout<<"Customer updated successfully!"<<endl;
            notFound= 0;
            break;
        }

    }
    if(notFound){
        cout<<"Error :  Id Not Found"<<endl;
        }
    indexFile.close();
}

void FileManager::deleteCustomer(){
    ifstream indexFile("data/customers/customer_index.txt");
    ofstream tempFile("data/customers/temp.txt");
    string fileName;
    int searchId;
    int notFound=1;

    cout<<"Enter ID : ";
    cin>>searchId;

    while(getline(indexFile,fileName)){
        int pos=fileName.find("_");
        string idstr=fileName.substr(0,pos);
        int id=stoi(idstr);

        if(id==searchId){
            string path="data/customers/"+fileName;

            if(remove(path.c_str())==0){
                cout<<"Customer deleted successfully!"<<endl;
            }
            else{
                cout<<"Error deleting customer!"<<endl;
            }

            notFound=0;
        }
        else{
            tempFile<<fileName<<endl;
        }
    }

    indexFile.close();
    tempFile.close();

    remove("data/customers/customer_index.txt");
    rename("data/customers/temp.txt","data/customers/customer_index.txt");

    if(notFound){
        cout<<"Error : Id Not Found"<<endl;
    }
}

int FileManager::getNextCustomerId(){
    ifstream indexFile("data/customers/customer_index.txt");
    string fileName;
    int maxId=999;

    while(getline(indexFile,fileName)){
        int pos=fileName.find('_');
        int id=stoi(fileName.substr(0,pos));

        if(id>maxId){
            maxId=id;
        }
    }

    indexFile.close();
    return maxId+1;
}

bool FileManager::findId(int searchId,string &fileName,string indexPath){
    ifstream indexFile(indexPath);

    while(getline(indexFile,fileName)){
        int pos=fileName.find("_");
        string idstr=fileName.substr(0,pos);
        int id=stoi(idstr);

        if(id==searchId){
            indexFile.close();
            return true;
        }
    }

    indexFile.close();
    return false;
}

void FileManager::savePolicy(Policy policy){
    string fileName=to_string(policy.getPolicyId())+"_"+to_string(policy.getCustomerId())+".txt";
    string path="data/policies/"+fileName;

    ofstream file(path);

    file<<policy.getPolicyId()<<endl;
    file<<policy.getCustomerId()<<endl;
    file<<policy.getInsuranceType()<<endl;

    if(policy.getInsuranceType()=="Life"||policy.getInsuranceType()=="Health"){
        file<<policy.getAge()<<endl;
        file<<policy.getCoverageAmount()<<endl;
    }
    else if(policy.getInsuranceType()=="Vehicle"){
        file<<policy.getVehicleValue()<<endl;
        file<<policy.getVehicleType()<<endl;
    }
    else if(policy.getInsuranceType()=="Property"){
        file<<policy.getPropertyValue()<<endl;
    }

    file<<policy.getDuration()<<endl;
    file<<policy.getPremium()<<endl;
    file<<policy.getStartDate()<<endl;
    file<<policy.getEndDate()<<endl;
    file<<policy.getStatus()<<endl;
    file<<policy.getPaymentStatus()<<endl;
    file<<policy.getPaidAmount()<<endl;
    file<<policy.getRenewalCount()<<endl;
    file.close();

    ofstream indexFile("data/policies/policy_index.txt",ios::app);
    indexFile<<fileName<<endl;
    indexFile.close();

    cout<<"Policy saved successfully!"<<endl;
}

void FileManager::policyView(int mode){
    ifstream indexFile("data/policies/policy_index.txt");
    string fileName;

    int searchId=0;
    if(mode==2){
        cout<<"Enter Policy ID: ";
        cin>>searchId;
    }

    int found=0;

    while(getline(indexFile,fileName)){
        int policyIdFromFile=stoi(fileName.substr(0,fileName.find("_")));

        if(mode==2 && policyIdFromFile!=searchId){
            continue;
        }

        string path="data/policies/"+fileName;
        ifstream file(path);

        if(!file){
            continue;
        }

        int policyId,customerId,age=0,duration,renewalCount;
        double coverageAmount=0,vehicleValue=0,propertyValue=0,premium,paidAmount;
        string insuranceType,vehicleType,startDate,endDate,status,paymentStatus;

        file>>policyId;
        file>>customerId;
        file.ignore();
        getline(file,insuranceType);

        cout<<"Policy ID: "<<policyId<<endl;
        cout<<"Customer ID: "<<customerId<<endl;
        cout<<"Insurance Type: "<<insuranceType<<endl;

        if(insuranceType=="Life"||insuranceType=="Health"){
            file>>age;
            file>>coverageAmount;

            cout<<"Age: "<<age<<endl;
            cout<<"Coverage Amount: "<<coverageAmount<<endl;
        }
        else if(insuranceType=="Vehicle"){
            file>>vehicleValue;
            file.ignore();
            getline(file,vehicleType);

            cout<<"Vehicle Value: "<<vehicleValue<<endl;
            cout<<"Vehicle Type: "<<vehicleType<<endl;
        }
        else if(insuranceType=="Property"){
            file>>propertyValue;

            cout<<"Property Value: "<<propertyValue<<endl;
        }

        file>>duration;
        file>>premium;
        file.ignore();
        getline(file,startDate);
        getline(file,endDate);
        getline(file,status);
        getline(file,paymentStatus);
        file>>paidAmount;
        file>>renewalCount;

        cout<<"Duration: "<<duration<<" Months"<<endl;
        cout<<"Premium: "<<premium<<endl;
        cout<<"Start Date: "<<startDate<<endl;
        cout<<"End Date: "<<endDate<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Payment Status: "<<paymentStatus<<endl;
        cout<<"Paid Amount: "<<paidAmount<<endl;
        cout<<"Renewal Count: "<<renewalCount<<endl;
        cout<<"-----------------------------"<<endl;

        file.close();
        found=1;

        if(mode==2){
            break;
        }
    }

    if(!found){
        if(mode==2){
            cout<<"Error: ID Not Found"<<endl;
        }
        else{
            cout<<"No Policies Found!"<<endl;
        }
    }

    indexFile.close();
}

void FileManager::updatePolicy(){
    int searchId;
    string fileName;

    cout<<"Enter Policy ID: ";
    cin>>searchId;

    if(findId(searchId,fileName,"data/policies/policy_index.txt")){
        string path="data/policies/"+fileName;
        ifstream file(path);

        if(!file){
            cout<<"Error opening policy file!"<<endl;
            return;
        }

        int policyId,customerId,age=0,duration,renewalCount;
        double coverageAmount=0,vehicleValue=0,propertyValue=0,premium,paidAmount;
        string insuranceType,vehicleType,startDate,endDate,status,paymentStatus;

        file>>policyId;
        file>>customerId;
        file.ignore();
        getline(file,insuranceType);

        if(insuranceType=="Life"||insuranceType=="Health"){
            file>>age;
            file>>coverageAmount;
        }
        else if(insuranceType=="Vehicle"){
            file>>vehicleValue;
            file.ignore();
            getline(file,vehicleType);
        }
        else if(insuranceType=="Property"){
            file>>propertyValue;
        }

        file>>duration;
        file>>premium;
        file.ignore();
        getline(file,startDate);
        getline(file,endDate);
        getline(file,status);
        getline(file,paymentStatus);
        file>>paidAmount;
        file>>renewalCount;

        file.close();

        int choice;

        cout<<"1. Update Insurance Details"<<endl;
        cout<<"2. Update Start Date"<<endl;
        cout<<"3. Update End Date"<<endl;
        cout<<"4. Update Status"<<endl;
        cout<<"5. Update All"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
        case 1:
            if(insuranceType=="Life"||insuranceType=="Health"){
                cout<<"Enter New Age: ";
                cin>>age;
                cout<<"Enter New Coverage Amount: ";
                cin>>coverageAmount;
            }
            else if(insuranceType=="Vehicle"){
                cout<<"Enter New Vehicle Value: ";
                cin>>vehicleValue;
                cin.ignore();
                cout<<"Enter New Vehicle Type: ";
                getline(cin,vehicleType);
            }
            else if(insuranceType=="Property"){
                cout<<"Enter New Property Value: ";
                cin>>propertyValue;
            }
            break;

        case 2:
            cout<<"Enter New Start Date: ";
            getline(cin,startDate);
            break;

        case 3:
            cout<<"Enter New End Date: ";
            getline(cin,endDate);
            break;

        case 4:
            cout<<"Enter New Status: ";
            getline(cin,status);
            break;

        case 5:
            if(insuranceType=="Life"||insuranceType=="Health"){
                cout<<"Enter New Age: ";
                cin>>age;
                cout<<"Enter New Coverage Amount: ";
                cin>>coverageAmount;
            }
            else if(insuranceType=="Vehicle"){
                cout<<"Enter New Vehicle Value: ";
                cin>>vehicleValue;
                cin.ignore();
                cout<<"Enter New Vehicle Type: ";
                getline(cin,vehicleType);
            }
            else if(insuranceType=="Property"){
                cout<<"Enter New Property Value: ";
                cin>>propertyValue;
            }

            cin.ignore();

            cout<<"Enter New Start Date: ";
            getline(cin,startDate);
            cout<<"Enter New End Date: ";
            getline(cin,endDate);
            cout<<"Enter New Status: ";
            getline(cin,status);
            break;

        default:
            cout<<"Invalid choice!"<<endl;
            return;
        }

        if(choice==1||choice==5){
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

            if(paidAmount>=premium){
                paymentStatus="Paid";
            }
            else if(paidAmount>0){
                paymentStatus="Partial";
            }
            else{
                paymentStatus="Pending";
            }
        }

        ofstream outfile(path);

        if(!outfile){
            cout<<"Error updating policy file!"<<endl;
            return;
        }

        outfile<<policyId<<endl;
        outfile<<customerId<<endl;
        outfile<<insuranceType<<endl;

        if(insuranceType=="Life"||insuranceType=="Health"){
            outfile<<age<<endl;
            outfile<<coverageAmount<<endl;
        }
        else if(insuranceType=="Vehicle"){
            outfile<<vehicleValue<<endl;
            outfile<<vehicleType<<endl;
        }
        else if(insuranceType=="Property"){
            outfile<<propertyValue<<endl;
        }

        outfile<<duration<<endl;
        outfile<<premium<<endl;
        outfile<<startDate<<endl;
        outfile<<endDate<<endl;
        outfile<<status<<endl;
        outfile<<paymentStatus<<endl;
        outfile<<paidAmount<<endl;
        outfile<<renewalCount<<endl;

        outfile.close();

        cout<<"Policy updated successfully!"<<endl;

        if(choice==1||choice==5){
            cout<<"New Premium: "<<premium<<endl;
            cout<<"Payment Status: "<<paymentStatus<<endl;
        }
    }
    else{
        cout<<"Error: ID Not Found"<<endl;
    }
}

void FileManager::cancelPolicy(){
    int searchId;
    string fileName;

    cout<<"Enter Policy ID: ";
    cin>>searchId;

    if(findId(searchId,fileName,"data/policies/policy_index.txt")){
        string path="data/policies/"+fileName;
        ifstream file(path);

        if(!file){
            cout<<"Error opening policy file!"<<endl;
            return;
        }

        int policyId,customerId,age=0,duration,renewalCount;
        double coverageAmount=0,vehicleValue=0,propertyValue=0,premium,paidAmount;
        string insuranceType,vehicleType,startDate,endDate,status,paymentStatus;

        file>>policyId;
        file>>customerId;
        file.ignore();
        getline(file,insuranceType);

        if(insuranceType=="Life"||insuranceType=="Health"){
            file>>age;
            file>>coverageAmount;
        }
        else if(insuranceType=="Vehicle"){
            file>>vehicleValue;
            file.ignore();
            getline(file,vehicleType);
        }
        else if(insuranceType=="Property"){
            file>>propertyValue;
        }

        file>>duration;
        file>>premium;
        file.ignore();
        getline(file,startDate);
        getline(file,endDate);
        getline(file,status);
        getline(file,paymentStatus);
        file>>paidAmount;
        file>>renewalCount;

        file.close();

        if(status=="Active"){
            status="Cancelled";

            ofstream outfile(path);

            if(!outfile){
                cout<<"Error updating policy file!"<<endl;
                return;
            }

            outfile<<policyId<<endl;
            outfile<<customerId<<endl;
            outfile<<insuranceType<<endl;

            if(insuranceType=="Life"||insuranceType=="Health"){
                outfile<<age<<endl;
                outfile<<coverageAmount<<endl;
            }
            else if(insuranceType=="Vehicle"){
                outfile<<vehicleValue<<endl;
                outfile<<vehicleType<<endl;
            }
            else if(insuranceType=="Property"){
                outfile<<propertyValue<<endl;
            }

            outfile<<duration<<endl;
            outfile<<premium<<endl;
            outfile<<startDate<<endl;
            outfile<<endDate<<endl;
            outfile<<status<<endl;
            outfile<<paymentStatus<<endl;
            outfile<<paidAmount<<endl;
            outfile<<renewalCount<<endl;

            outfile.close();

            cout<<"Policy cancelled successfully!"<<endl;
        }
        else{
            cout<<"Policy is not Active. Current Status: "<<status<<endl;
        }
    }
    else{
        cout<<"Error: ID Not Found"<<endl;
    }
}

void FileManager::viewActivePolicies(){
    ifstream indexFile("data/policies/policy_index.txt");
    string fileName;
    int found=0;

    if(!indexFile){
        cout<<"Error opening policy index!"<<endl;
        return;
    }

    while(getline(indexFile,fileName)){
        string path="data/policies/"+fileName;
        ifstream file(path);

        if(!file){
            continue;
        }

        int policyId,customerId,age=0,duration,renewalCount;
        double coverageAmount=0,vehicleValue=0,propertyValue=0,premium,paidAmount;
        string insuranceType,vehicleType,startDate,endDate,status,paymentStatus;

        file>>policyId;
        file>>customerId;
        file.ignore();
        getline(file,insuranceType);

        if(insuranceType=="Life"||insuranceType=="Health"){
            file>>age;
            file>>coverageAmount;
        }
        else if(insuranceType=="Vehicle"){
            file>>vehicleValue;
            file.ignore();
            getline(file,vehicleType);
        }
        else if(insuranceType=="Property"){
            file>>propertyValue;
        }

        file>>duration;
        file>>premium;
        file.ignore();
        getline(file,startDate);
        getline(file,endDate);
        getline(file,status);
        getline(file,paymentStatus);
        file>>paidAmount;
        file>>renewalCount;

        if(file && status=="Active"){
            cout<<"Policy ID: "<<policyId<<endl;
            cout<<"Customer ID: "<<customerId<<endl;
            cout<<"Insurance Type: "<<insuranceType<<endl;

            if(insuranceType=="Life"||insuranceType=="Health"){
                cout<<"Age: "<<age<<endl;
                cout<<"Coverage Amount: "<<coverageAmount<<endl;
            }
            else if(insuranceType=="Vehicle"){
                cout<<"Vehicle Value: "<<vehicleValue<<endl;
                cout<<"Vehicle Type: "<<vehicleType<<endl;
            }
            else if(insuranceType=="Property"){
                cout<<"Property Value: "<<propertyValue<<endl;
            }

            cout<<"Duration: "<<duration<<" Months"<<endl;
            cout<<"Premium: "<<premium<<endl;
            cout<<"Start Date: "<<startDate<<endl;
            cout<<"End Date: "<<endDate<<endl;
            cout<<"Status: "<<status<<endl;
            cout<<"Payment Status: "<<paymentStatus<<endl;
            cout<<"Paid Amount: "<<paidAmount<<endl;
            cout<<"Renewal Count: "<<renewalCount<<endl;
            cout<<"-----------------------------"<<endl;

            found=1;
        }

        file.close();
    }

    if(!found){
        cout<<"No Active Policies Found!"<<endl;
    }

    indexFile.close();
}

void FileManager::makePayment(){
    int searchId;
    string fileName;

    cout<<"Enter Policy ID: ";
    cin>>searchId;

    if(!findId(searchId,fileName,"data/policies/policy_index.txt")){
        cout<<"Error: Policy ID Not Found"<<endl;
        return;
    }

    string path="data/policies/"+fileName;
    ifstream file(path);

    if(!file){
        cout<<"Error opening policy file!"<<endl;
        return;
    }

    int policyId,customerId,age=0,duration,renewalCount;
    double coverageAmount=0,vehicleValue=0,propertyValue=0,premium,paidAmount;
    string insuranceType,vehicleType,startDate,endDate,status,paymentStatus;

    file>>policyId;
    file>>customerId;
    file.ignore();
    getline(file,insuranceType);

    if(insuranceType=="Life"||insuranceType=="Health"){
        file>>age;
        file>>coverageAmount;
    }
    else if(insuranceType=="Vehicle"){
        file>>vehicleValue;
        file.ignore();
        getline(file,vehicleType);
    }
    else if(insuranceType=="Property"){
        file>>propertyValue;
    }

    file>>duration;
    file>>premium;
    file.ignore();
    getline(file,startDate);
    getline(file,endDate);
    getline(file,status);
    getline(file,paymentStatus);
    file>>paidAmount;
    file>>renewalCount;
    file.close();

    if(status!="Active"){
        cout<<"Payment is not allowed for this policy!"<<endl;
        return;
    }

    double outstanding=premium-paidAmount;

    cout<<"Total Premium: "<<premium<<endl;
    cout<<"Already Paid: "<<paidAmount<<endl;
    cout<<"Outstanding Amount: "<<outstanding<<endl;

    if(outstanding<=0){
        cout<<"Policy premium is already paid!"<<endl;
        return;
    }

    double amount;
    cout<<"Enter Payment Amount: ";
    cin>>amount;

    if(amount<=0||amount>outstanding){
        cout<<"Invalid Amount! Enter an amount up to "<<outstanding<<endl;
        return;
    }

    string paymentDate;
    cin.ignore();
    cout<<"Enter Payment Date (DD-MM-YYYY): ";
    getline(cin,paymentDate);

    paidAmount+=amount;

    if(paidAmount>=premium){
        paymentStatus="Paid";
    }
    else{
        paymentStatus="Partial";
    }

    ofstream outfile(path);

    if(!outfile){
        cout<<"Error updating policy file!"<<endl;
        return;
    }

    outfile<<policyId<<endl;
    outfile<<customerId<<endl;
    outfile<<insuranceType<<endl;

    if(insuranceType=="Life"||insuranceType=="Health"){
        outfile<<age<<endl;
        outfile<<coverageAmount<<endl;
    }
    else if(insuranceType=="Vehicle"){
        outfile<<vehicleValue<<endl;
        outfile<<vehicleType<<endl;
    }
    else if(insuranceType=="Property"){
        outfile<<propertyValue<<endl;
    }

    outfile<<duration<<endl;
    outfile<<premium<<endl;
    outfile<<startDate<<endl;
    outfile<<endDate<<endl;
    outfile<<status<<endl;
    outfile<<paymentStatus<<endl;
    outfile<<paidAmount<<endl;
    outfile<<renewalCount<<endl;
    outfile.close();

    ofstream historyFile("data/payments/payment_history.txt",ios::app);

    if(!historyFile){
        cout<<"Warning: Payment saved, but history file could not be opened!"<<endl;
        return;
    }

    historyFile<<policyId<<"|"<<customerId<<"|"<<amount<<"|"<<paymentDate<<endl;
    historyFile.close();

    cout<<"Payment Successful!"<<endl;
    cout<<"Payment Status: "<<paymentStatus<<endl;
    cout<<"Remaining Amount: "<<premium-paidAmount<<endl;
}

void FileManager::paymentHistory(){
    ifstream file("data/payments/payment_history.txt");

    if(!file){
        cout<<"No Payment History Found!"<<endl;
        return;
    }

    string line;
    int found=0;

    while(getline(file,line)){
        if(line.empty()){
            continue;
        }

        int pos1=line.find("|");
        int pos2=line.find("|",pos1+1);
        int pos3=line.find("|",pos2+1);

        if(pos1==string::npos||pos2==string::npos||pos3==string::npos){
            continue;
        }

        int policyId=stoi(line.substr(0,pos1));
        int customerId=stoi(line.substr(pos1+1,pos2-pos1-1));
        double amount=stod(line.substr(pos2+1,pos3-pos2-1));
        string paymentDate=line.substr(pos3+1);

        cout<<"Policy ID: "<<policyId<<endl;
        cout<<"Customer ID: "<<customerId<<endl;
        cout<<"Payment Amount: "<<amount<<endl;
        cout<<"Payment Date: "<<paymentDate<<endl;
        cout<<"-----------------------------"<<endl;

        found=1;
    }

    if(!found){
        cout<<"No Payment History Found!"<<endl;
    }

    file.close();
}
