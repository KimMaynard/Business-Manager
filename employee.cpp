#include "employee.h"
#include <string>
#include <random>

Employee::Employee(const std::string& name, const std::string& employeeId)
    : name(name), employeeId(employeeId), position("unemployed"), hourlyRate(0.0)
{
    //position is initially set to "unemployed," and hourlyRate set to 0. Calling assignPositionAndRate() to set them to something else
    assignPositionAndRate();
}


void Employee::assignPositionAndRate(){
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
   

void Employee::setName(const std::string& employeeName){
    if(!employeeName.empty()){
        name = employeeName;
    }
}

std::string Employee::getName() const{
    return name;
}

std::string Employee::getEmployeeId() const{
    return employeeId;
}

std::string Employee::getPosition() const{
    return position;
}

double Employee::getHourlyRate() const{
    return hourlyRate;
}