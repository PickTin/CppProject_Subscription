#include "InternetConnection.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace BillingSystem {
    InternetConnection::InternetConnection(string ln, string fn, string mn, string addr, string ct, string pd, string cn, int dv, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), connectionName(cn), dataVolume(dv), totalAmount(ta), month(m), year(y) {}

    void InternetConnection::display() const {
        cout << left << setw(20) << "Type" << setw(20) << "Last Name" << setw(20) << "First Name" << setw(20) << "Middle Name"
            << setw(20) << "Address" << setw(20) << "City" << setw(20) << "Passport Data" << setw(20) << "Connection"
            << setw(15) << "Data Volume" << setw(10) << "Total" << "\n";
        cout << setw(20) << "InternetConn" << setw(20) << lastName << setw(20) << firstName << setw(20) << middleName
            << setw(20) << address << setw(20) << city << setw(20) << passportData << setw(20) << connectionName
            << setw(15) << dataVolume << " MB" << setw(10) << totalAmount << "\n";
    }

    string InternetConnection::getConnectionName() const {
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
