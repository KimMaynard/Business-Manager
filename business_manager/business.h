//if business.h is not defined, define it (start of header guard)
#ifndef BUSINESS_H
//define business.h to prevent multiple inclusions
#define BUSINESS_H
#include <string>
class Business
{
public:
    //constructor
    Business(const std::string& businessName, const std::string& manager, const std::string& businessId);
    void displayInfo();

private:
    std::string businessName;
    std::string manager;
    std::string businessId;
    double worth;

};


#endif

