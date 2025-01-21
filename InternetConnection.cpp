#include "InternetConnection.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace BillingSystem {
    InternetConnection::InternetConnection(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, std::string cn, int dv, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), connectionName(cn), dataVolume(dv), totalAmount(ta), month(m), year(y) {}

    void InternetConnection::display() const {
        std::cout << std::left << std::setw(20) << "Type" << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(20) << "Middle Name"
            << std::setw(20) << "Address" << std::setw(20) << "City" << std::setw(20) << "Passport Data" << std::setw(20) << "Connection" << "Data Volume" << "Total" << "\n";
        std::cout << std::setw(20) << "InternetConn" << std::setw(20) << lastName << std::setw(20) << firstName << std::setw(20) << middleName
            << std::setw(20) << address << std::setw(20) << city << std::setw(20) << passportData << std::setw(20) << connectionName << dataVolume << " MB" << totalAmount << "\n";
    }

    std::string InternetConnection::getConnectionName() const {
        return connectionName;
    }

    int InternetConnection::getDataVolume() const {
        return dataVolume;
    }

    double InternetConnection::getTotalAmount() const {
        return totalAmount;
    }

    int InternetConnection::getMonth() const {
        return month;
    }

    int InternetConnection::getYear() const {
        return year;
    }
}
