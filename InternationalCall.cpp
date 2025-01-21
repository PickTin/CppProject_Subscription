#include "InternationalCall.h"
#include <iostream>

using namespace std;

namespace BillingSystem {
    InternationalCall::InternationalCall(string ln, string fn, string mn, string addr, string ct, string pd,
        string cntry, string cityC, int dur, double p, double ta, int m, int y)
        : Subscription(ln, fn, mn, addr, ct, pd), country(cntry), cityCall(cityC),
        duration(dur), price(p), totalAmount(ta), month(m), year(y) {}

    void InternationalCall::display() const {
        cout << "International Call: " << lastName << " " << firstName << " (" << country << ", " << cityCall
            << ") Duration: " << duration << " min, Price: $" << price << ", Total: $" << totalAmount << "\n";
    }
}