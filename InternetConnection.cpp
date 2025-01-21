#include "InternetConnection.h"
#include <iostream>

using namespace std;

namespace BillingSystem {
    InternetConnection::InternetConnection(string ln, string fn, string mn, string addr, string ct, string pd,
        string cn, int dv, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), connectionName(cn), dataVolume(dv), totalAmount(ta), month(m), year(y) {}

    void InternetConnection::display() const {
        cout << "Internet Connection: " << lastName << " " << firstName << " Connection: " << connectionName
            << ", Data: " << dataVolume << " MB, Total: $" << totalAmount << "\n";
    }
}