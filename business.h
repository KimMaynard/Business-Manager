//if business.h is not defined, define it (start of header guard)
#ifndef BUSINESS_H
//define business.h to prevent multiple inclusions
#define BUSINESS_H
#include <string>
#include <vector>
#include "employee.h"
#include "bankAccount.h"

class Business
{
public:
    //constructor
    Business(const std::string& businessName, const std::string& owner, const std::string& businessId, const std::string& bankAccountId);
    void displayInfo();
    void setWorth();
    void addEmployee(const Employee& employee);
    void displayEmployees() const;
    const Employee* findEmployee(const std::string& employeeId) const;
    bool deposit(double amount);
    bool withdrawal(double amount);
    double getBalance();
    

private:
    std::string businessName;
    std::string owner;
    std::string businessId;
    double worth;
    double amount;
    std::vector<Employee> employees;
    BankAccount bankAccount;

};  


#endif
