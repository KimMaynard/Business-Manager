#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
public:
    Employee(const std::string& name, const std::string& employeeId);
    void displayInfo();
    void setPositionAndRate();

private:
    std::string name;
    std::string employeeId;
    std::string position;
    double hourlyRate;
};

#endif