//include header file
#include "business.h"
#include <iostream>
#include <random>
#include <iomanip>


Business::Business(const std::string& businessName, const std::string& owner, const std::string& businessId)
    : businessName(businessName), owner(owner), businessId(businessId), worth(0.0)
{
    //worth is initially set to 0. Calling setWorth() to assign it a random worth
    setWorth();
}


void Business::displayInfo()
{
    std::cout << "Business name: " << businessName << std::endl;
    std::cout << "Owner: " << owner << std::endl;
    std::cout << "Business ID: " << businessId << std::endl;
    //only show 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Worth: $" << worth << std::endl;

}

void Business::setWorth(){
    //initialize a random num generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(20000, 50000);

    //generate a random num in the range [20000, 50000]
    worth = distrib(gen);
}

const Employee* Business::findEmployee(const std::string& employeeId) const{
    for(const Employee& employee : employees){
        if(employee.getEmployeeId() == employeeId){
            return &employee;
        }
    }
    return nullptr;
}

void Business::addEmployee(const Employee& employee){
    employees.push_back(employee);
}


void Business::displayEmployees() const{
    for(const Employee& employee : employees){
        employee.displayInfo();
        std::cout << "-------------------" << std::endl;
    }
}