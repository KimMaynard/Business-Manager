#include "employee.h"
#include <string>
#include <iostream>
#include <random>
#include <iomanip>

Employee::Employee(const std::string& name, const std::string& employeeId)
    : name(name), employeeId(employeeId), position("unemployed"), hourlyRate(0.0)
{
    //position is initially set to "unemployed." Calling setPosition() to set it to something else
    setPositionAndRate();
}

void Employee::displayInfo(){
    std::cout << "Employee name: " << name << std::endl;
    std::cout << "Employee ID: " << employeeId << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Hourly Rate: $" << hourlyRate << std::endl;
}

void Employee::setPositionAndRate(){
    int num;
    //initialize a rand num generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 4);
    //generate a random num in the range [0, 4]
    num = distrib(gen);

    switch (num)
    {
        case 0:
            position = "associate";
            hourlyRate = 15.0;
            break;
        case 1:
            position = "associate";
            hourlyRate = 15.0;
            break;
        case 2:
            position = "shift lead";
            hourlyRate = 20.0;
            break;
        case 3:
            position = "assistant manager";
            hourlyRate = 23.0;
            break;
        case 4:
            position = "general manager";
            hourlyRate = 25.0;
            break;
        default:
            position = "associate";
            hourlyRate = 15.0;
            break;
    }

}