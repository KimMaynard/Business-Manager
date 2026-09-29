//include header file
#include "business.h"
#include <iostream>

Business::Business(const std::string& businessName, const std::string& manager, const std::string& businessId)
    : businessName(businessName), manager(manager), businessId(businessId), worth(0.0)
{
}

void Business::displayInfo()
{
    std::cout << "Business name: " << businessName << std::endl;
    std::cout << "Manager: " << manager << std::endl;
    std::cout << "Business ID: " << businessId << std::endl;
}
