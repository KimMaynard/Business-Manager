#include "business.h"
#include "employee.h"
#include "bankAccount.h"
#include <iostream>

int main()
{   
    Business sushiKing("Sushi King", "Kim", "K945", "J123454");
    Business coffeeHaus("Coffee Haus", "Ryan", "C3784", "435k354");

    sushiKing.deposit(700.75);
    std::cout << "Coffee Haus balance: " << coffeeHaus.getBalance() << std::endl;

    

    return 0;
}

