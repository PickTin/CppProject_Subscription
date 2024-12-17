#include "CityCall.h"
#include <iostream>
#include <iomanip>

namespace BillingSystem {
    CityCall::CityCall(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, double t, int d)
        : Subscription(ln, fn, mn, addr, ct, pd), tariff(t), duration(d) {}

    void CityCall::display() const {
        std::cout << std::left << std::setw(15) << lastName
            << std::setw(10) << firstName
            << std::setw(10) << middleName
            << std::setw(20) << address
            << std::setw(15) << city
            << std::setw(15) << passportData
            << std::setw(10) << tariff
            << std::setw(10) << duration << " min\n";
    }
}
