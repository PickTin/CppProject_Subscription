#include "InternationalCall.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace BillingSystem {
    InternationalCall::InternationalCall(string ln, string fn, string mn, string addr, string ct, string pd, string cntry, string cityC, int dur, double p, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), country(cntry), cityCall(cityC), duration(dur), price(p), totalAmount(ta), month(m), year(y) {}

    void InternationalCall::display() const {
        cout << left << setw(20) << "Type" << setw(20) << "Last Name" << setw(20) << "First Name" << setw(20) << "Middle Name"
            << setw(20) << "Address" << setw(20) << "City" << setw(20) << "Passport Data" << setw(20) << "Country" << setw(15) << "CityCall"
            << setw(10) << "Duration" << setw(10) << "Price" << "Total" << "\n";
        cout << setw(20) << "InternationalCall" << setw(20) << lastName << setw(20) << firstName << setw(20) << middleName
            << setw(20) << address << setw(20) << city << setw(20) << passportData << setw(20) << country << setw(15) << cityCall
            << setw(10) << duration << setw(8) << " min" << setw(10) << price << setw(10) << totalAmount << "\n";
    }

    string InternationalCall::getCountry() const {
        return country;
    }

    string InternationalCall::getCityCall() const {
        return cityCall;
    }

    int InternationalCall::getDuration() const {
        return duration;
    }

    double InternationalCall::getPrice() const {
        return price;
    }

    double InternationalCall::getTotalAmount() const {
        return totalAmount;
    }

    int InternationalCall::getMonth() const {
        return month;
    }

    int InternationalCall::getYear() const {
        return year;
    }
}
