//if business.h is not defined, define it (start of header guard)
#ifndef BUSINESS_H
//define business.h to prevent multiple inclusions
#define BUSINESS_H
#include <string>
#include <vector>
#include "employee.h"
#include "bankAccount.h"
#include <mutex>
#include <optional>
#include <cstddef>

class Business
{
public:

    Business(const std::string& businessName, const std::string& owner, const std::string& businessId, const std::string& bankAccountId);
    void setBusinessName(const std::string& name);
    void setOwner(const std::string& businessOwner);
    std::string getBusinessName() const;
    std::string getOwner() const;
    std::string getBusinessId() const;
    double getWorth() const;
    void addEmployee(const Employee& employee);
    std::optional<Employee> findEmployee(const std::string& employeeId) const;
    bool deposit(double amount);
    bool withdrawal(double amount);
    double getBalance() const;
    

private:
    std::string businessName;
    std::string owner;
    std::string businessId;
    std::vector<Employee> employees;
    BankAccount bankAccount;
    double worth;
    mutable std::mutex businessMutex;
    void setWorth();
};  


#endif
