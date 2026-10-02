#include "business.h"

#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::fixed << std::setprecision(2);

    Business business(
        "Example Motors",
        "Kimberly Maynard",
        "BUS-001",
        "ACC-001"
    );

    std::cout << "Business name: " << business.getBusinessName() << '\n';
    std::cout << "Owner: " << business.getOwner() << '\n';
    std::cout << "Business ID: " << business.getBusinessId() << '\n';
    std::cout << "Business worth: $" << business.getWorth() << '\n';
    std::cout << "Initial balance: $" << business.getBalance() << "\n\n";

    business.setBusinessName("Updated Motors");
    business.setOwner("Updated Owner");

    std::cout << "Updated business name: "
              << business.getBusinessName() << '\n';

    std::cout << "Updated owner: "
              << business.getOwner() << "\n\n";

    Employee employee1("Alice Johnson", "EMP-001");
    Employee employee2("David Smith", "EMP-002");

    employee1.setName("Alice Williams");

    business.addEmployee(employee1);
    business.addEmployee(employee2);

    std::cout << "Searching for EMP-001:\n";

    auto foundEmployee = business.findEmployee("EMP-001");

    if (foundEmployee.has_value())
    {
        std::cout << "Name: " << foundEmployee->getName() << '\n';
        std::cout << "Employee ID: "
                  << foundEmployee->getEmployeeId() << '\n';
        std::cout << "Position: "
                  << foundEmployee->getPosition() << '\n';
        std::cout << "Hourly rate: $"
                  << foundEmployee->getHourlyRate() << "\n\n";
    }
    else
    {
        std::cout << "Employee not found.\n\n";
    }

    std::cout << "Searching for EMP-999:\n";

    auto missingEmployee = business.findEmployee("EMP-999");

    if (missingEmployee.has_value())
    {
        std::cout << "Employee found unexpectedly.\n";
    }
    else
    {
        std::cout << "Employee not found, as expected.\n";
    }

    std::cout << "\nDepositing $1,000: "
              << business.deposit(1000.00) << '\n';

    std::cout << "Balance: $"
              << business.getBalance() << '\n';

    std::cout << "Withdrawing $250: "
              << business.withdrawal(250.00) << '\n';

    std::cout << "Balance: $"
              << business.getBalance() << '\n';

    std::cout << "Invalid deposit: "
              << business.deposit(-50.00) << '\n';

    std::cout << "Overdraft attempt: "
              << business.withdrawal(5000.00) << '\n';

    std::cout << "Final balance: $"
              << business.getBalance() << '\n';

    return 0;
}
