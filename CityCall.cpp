#include "CityCall.h"
#include <iostream>

using namespace std;

namespace BillingSystem {
    CityCall::CityCall(string ln, string fn, string mn, string addr, string ct, string pd,
        double t, int dur, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), tariff(t), duration(dur), totalAmount(ta), month(m), year(y) {}

    void CityCall::display() const {
        cout << "City Call: " << lastName << " " << firstName << " Tariff: $" << tariff
            << ", Duration: " << duration << " min, Total: $" << totalAmount << "\n";
    }
}
