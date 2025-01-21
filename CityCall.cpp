#include "CityCall.h"
#include <iostream>

using namespace std;
#include <iomanip>

namespace BillingSystem {
    CityCall::CityCall(string ln, string fn, string mn, string addr, string ct, string pd,
        double t, int dur, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), tariff(t), duration(dur), totalAmount(ta), month(m), year(y) {}
    CityCall::CityCall(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, double t, int d)
        : Subscription(ln, fn, mn, addr, ct, pd), tariff(t), duration(d) {}

    void CityCall::display() const {
        cout << "City Call: " << lastName << " " << firstName << " Tariff: $" << tariff
            << ", Duration: " << duration << " min, Total: $" << totalAmount << "\n";
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