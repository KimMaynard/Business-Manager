//include header file
#include "business.h"
#include <iostream>
#include <random>
#include <iomanip>


Business::Business(const std::string& businessName, const std::string& owner, const std::string& businessId, const std::string& bankAccountId)
    : businessName(businessName), owner(owner), businessId(businessId), bankAccount(bankAccountId), worth(0.0) 
{
    //worth is initially set to 0. Calling setWorth() to assign it a random worth
    setWorth();
}


void Business::displayInfo()
{
    std::lock_guard<std::mutex> lock(businessMutex);
    std::cout << "Business name: " << businessName << std::endl;
    std::cout << "Owner: " << owner << std::endl;
    std::cout << "Business ID: " << businessId << std::endl;
    //only show 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Worth: $" << worth << std::endl;

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


void Business::displayEmployees() const{
    std::lock_guard<std::mutex> lock(businessMutex);
    for(const Employee& employee : employees){
        employee.displayInfo();
        std::cout << "-------------------" << std::endl;
    }
}

bool Business::deposit(double amount){
    return bankAccount.deposit(amount);
}

bool Business::withdrawal(double amount){
    return bankAccount.withdraw(amount);
}

double Business::getBalance(){
    return bankAccount.getBalance();
}