#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
public:

    Employee(const std::string& name, const std::string& employeeId);
    void setName(const std::string&);
    std::string getName() const;
    std::string getEmployeeId() const;
    std::string getPosition() const;
    double getHourlyRate() const;


private:
    std::string name;
    std::string employeeId;
    std::string position;
    double hourlyRate;
    void assignPositionAndRate();
};

#endif