#include "Business.h"
#include "Employee.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector<Business> businesses;

    businesses.emplace_back("Joe's Coffee", "Joe", "B001");
    businesses.emplace_back("Kim's Sushi Bar", "Kim", "C002");
    businesses.emplace_back("McDonald's", "Bob", "D004");

    for (Business& business: businesses){
        business.displayInfo();
        std::cout << "------------" << std::endl;
    }

    std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;

    std::vector<Employee> employees;
    employees.emplace_back("Rebecca", "A331");
    employees.emplace_back("Josh", "K345");
    employees.emplace_back("Ryan", "L908");

    for(Employee& employee: employees){
        employee.displayInfo();
        std::cout << "---------" << std::endl;
    }

    return 0;
}
