#include "business.h"
#include "employee.h"
#include <iostream>

int main()
{
    // Create a business
    Business business("Joe's Coffee", "Joe", "B001");

    std::cout << "===== BUSINESS INFO =====" << std::endl;
    business.displayInfo();

    // Create employees
    std::cout << "\n===== CREATE EMPLOYEES =====" << std::endl;

    Employee employee1("Rebecca", "A331");
    Employee employee2("Josh", "K345");
    Employee employee3("Ryan", "L908");

    // Display individual employees
    employee1.displayInfo();
    std::cout << "----------------" << std::endl;

    employee2.displayInfo();
    std::cout << "----------------" << std::endl;

    employee3.displayInfo();

    // Add employees to the business
    business.addEmployee(employee1);
    business.addEmployee(employee2);
    business.addEmployee(employee3);

    // Display all employees belonging to the business
    std::cout << "\n===== BUSINESS EMPLOYEES =====" << std::endl;
    business.displayEmployees();

    // Find an existing employee
    std::cout << "\n===== FIND EMPLOYEE =====" << std::endl;

    const Employee* foundEmployee = business.findEmployee("K345");

    if (foundEmployee != nullptr)
    {
        std::cout << "Employee found!" << std::endl;
        foundEmployee->displayInfo();
    }
    else
    {
        std::cout << "Employee not found." << std::endl;
    }

    // Try to find an employee who doesn't exist
    std::cout << "\n===== FIND NON-EXISTENT EMPLOYEE =====" << std::endl;

    const Employee* missingEmployee = business.findEmployee("XYZ123");

    if (missingEmployee != nullptr)
    {
        std::cout << "Employee found!" << std::endl;
        missingEmployee->displayInfo();
    }
    else
    {
        std::cout << "Employee not found." << std::endl;
    }

    return 0;
}