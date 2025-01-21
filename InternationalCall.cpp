#include "InternationalCall.h"
#include <iostream>
#include <iomanip>
namespace BillingSystem {
    InternationalCall::InternationalCall(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, std::string cntry, std::string cityC, int dur, double p, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), country(cntry), cityCall(cityC), duration(dur), price(p), totalAmount(ta), month(m), year(y) {}

    void InternationalCall::display() const {
        std::cout << std::left << std::setw(20) << "Type" << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(20) << "Middle Name"
            << std::setw(20) << "Address" << std::setw(20) << "City" << std::setw(20) << "Passport Data" << std::setw(20) << "Country" << "City Call" << "Duration" << "Price" << "Total" << "\n";
        std::cout << std::setw(20) << "InternationalCall" << std::setw(20) << lastName << std::setw(20) << firstName << std::setw(20) << middleName
            << std::setw(20) << address << std::setw(20) << city << std::setw(20) << passportData << std::setw(20) << country << cityCall
            << duration << " min" << price << totalAmount << "\n";
    }

    std::string InternationalCall::getCountry() const {
        return country;
    }

    std::string InternationalCall::getCityCall() const {
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
