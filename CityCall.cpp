#include "CityCall.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace BillingSystem {
    CityCall::CityCall(string ln, string fn, string mn, string addr, string ct, string pd, double t, int d)
        : Subscription(ln, fn, mn, addr, ct, pd), tariff(t), duration(d) {}

    void CityCall::display() const {
        cout << left << setw(20) << "Type" << setw(20) << "Last Name" << setw(20) << "First Name" << setw(20) << "Middle Name"
            << setw(20) << "Address" << setw(20) << "City" << setw(20) << "Passport Data" << setw(20) << "Tariff" << "Duration" << "\n";
        cout << setw(20) << "CityCall" << setw(20) << lastName << setw(20) << firstName << setw(20) << middleName
            << setw(20) << address << setw(20) << city << setw(20) << passportData << setw(20) << tariff << duration << " min" << "\n";
    }

    double CityCall::getTariff() const {
        return tariff;
    }

    int CityCall::getDuration() const {
        return duration;
    }
}
