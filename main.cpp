#include "business.h"
#include "employee.h"

#include <iostream>
#include <thread>
#include <vector>

int main()
{
    std::cout << "===== CREATE BUSINESS =====\n";

    Business coffeeShop(
        "Joe's Coffee",
        "Joe",
        "B001",
        "COFFEE-001"
    );

    coffeeShop.displayInfo();

    std::cout << "\n===== CREATE EMPLOYEES =====\n";

    Employee employee1("Rebecca", "A331");
    Employee employee2("Josh", "K345");
    Employee employee3("Ryan", "L908");

    coffeeShop.addEmployee(employee1);
    coffeeShop.addEmployee(employee2);
    coffeeShop.addEmployee(employee3);

    coffeeShop.displayEmployees();

    std::cout << "\n===== FIND EXISTING EMPLOYEE =====\n";

    auto foundEmployee = coffeeShop.findEmployee("K345");

    if (foundEmployee.has_value())
    {
        std::cout << "Employee found:\n";
        foundEmployee->displayInfo();
    }
    else
    {
        std::cout << "Employee not found.\n";
    }

    std::cout << "\n===== FIND MISSING EMPLOYEE =====\n";

    auto missingEmployee = coffeeShop.findEmployee("XYZ123");

    if (missingEmployee.has_value())
    {
        std::cout << "Employee found:\n";
        missingEmployee->displayInfo();
    }
    else
    {
        std::cout << "Employee not found.\n";
    }

    std::cout << "\n===== TEST BANK ACCOUNT =====\n";

    coffeeShop.deposit(100.00);

    std::cout << "Balance after depositing $100: $"
              << coffeeShop.getBalance() << '\n';

    coffeeShop.withdrawal(25.00);

    std::cout << "Balance after withdrawing $25: $"
              << coffeeShop.getBalance() << '\n';

    bool withdrawalSuccessful = coffeeShop.withdrawal(1000.00);

    std::cout << "Attempt to withdraw $1000: "
              << (withdrawalSuccessful ? "successful" : "failed")
              << '\n';

    std::cout << "Current balance: $"
              << coffeeShop.getBalance() << '\n';

    std::cout << "\n===== TEST MULTITHREADING =====\n";

    std::vector<std::thread> threads;

    for (int threadNumber = 0; threadNumber < 4; ++threadNumber)
    {
        threads.emplace_back([&coffeeShop]()
        {
            for (int i = 0; i < 100; ++i)
            {
                coffeeShop.deposit(1.00);
            }
        });
    }

    for (std::thread& thread : threads)
    {
        thread.join();
    }

    std::cout << "Final balance after threaded deposits: $"
              << coffeeShop.getBalance() << '\n';

    std::cout << "\n===== TEST TWO BUSINESSES =====\n";

    Business bakery(
        "Joe's Bakery",
        "Joe",
        "B002",
        "BAKERY-001"
    );

    bakery.deposit(500.00);

    std::cout << "Coffee balance: $"
              << coffeeShop.getBalance() << '\n';

    std::cout << "Bakery balance: $"
              << bakery.getBalance() << '\n';

    return 0;
}