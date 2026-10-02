//include header file
#include "business.h"
#include <random>


Business::Business(const std::string& businessName, const std::string& owner, const std::string& businessId, const std::string& bankAccountId)
    : businessName(businessName), owner(owner), businessId(businessId), bankAccount(bankAccountId), worth(0.0) 
{
    //worth is initially set to 0. Calling setWorth() to assign it a random worth
    setWorth();
}


std::string Business::getOwner() const{
    std::lock_guard<std::mutex> lock(businessMutex);
    return owner;
}

std::string Business::getBusinessId() const{
    std::lock_guard<std::mutex> lock(businessMutex);
    return businessId;
}

std::string Business::getBusinessName() const{
    std::lock_guard<std::mutex> lock(businessMutex);
    return businessName;
}

void Business::setOwner(const std::string& businessOwner){
    std::lock_guard<std::mutex> lock(businessMutex);
    owner = businessOwner;
}

void Business::setBusinessName(const std::string& name){
    std::lock_guard<std::mutex> lock(businessMutex);
    businessName = name;
}

void Business::setWorth(){
    std::lock_guard<std::mutex> lock(businessMutex);
    //initialize a random num generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(20000, 50000);

    //generate a random num in the range [20000, 50000]
    worth = distrib(gen);
}

double Business::getWorth() const{
    std::lock_guard<std::mutex> lock(businessMutex);
    return worth;
}

 std::optional<Employee> Business::findEmployee(const std::string& employeeId) const{
    std::lock_guard<std::mutex> lock(businessMutex);
    for(const Employee& employee : employees){
        if(employee.getEmployeeId() == employeeId){
            return employee;
        }
    }

    return std::nullopt;
}

void Business::addEmployee(const Employee& employee){
    std::lock_guard<std::mutex> lock(businessMutex);
    employees.push_back(employee);
}

bool Business::deposit(double amount){
    return bankAccount.deposit(amount);
}

bool Business::withdrawal(double amount){
    return bankAccount.withdraw(amount);
}

double Business::getBalance() const{
    return bankAccount.getBalance();
}