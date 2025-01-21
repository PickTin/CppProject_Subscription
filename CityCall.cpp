#include "CityCall.h"
#include <iostream>
#include <iomanip>
namespace BillingSystem {
    CityCall::CityCall(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, double t, int d)
        : Subscription(ln, fn, mn, addr, ct, pd), tariff(t), duration(d) {}

    void CityCall::display() const {
        std::cout << std::left << std::setw(20) << "Type" << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(20) << "Middle Name"
            << std::setw(20) << "Address" << std::setw(20) << "City" << std::setw(20) << "Passport Data" << std::setw(20) << "Tariff" << "Duration" << "\n";
        std::cout << std::setw(20) << "CityCall" << std::setw(20) << lastName << std::setw(20) << firstName << std::setw(20) << middleName
            << std::setw(20) << address << std::setw(20) << city << std::setw(20) << passportData << std::setw(20) << tariff << duration << " min" << "\n";
    }

    double CityCall::getTariff() const {
        return tariff;
    }

    int CityCall::getDuration() const {
        return duration;
    }
}

    
