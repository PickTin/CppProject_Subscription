#include "Subscription.h"
#include <iostream>

using namespace std;

namespace BillingSystem {
    Subscription::Subscription(string ln, string fn, string mn, string addr, string ct, string pd)
        : lastName(ln), firstName(fn), middleName(mn), address(addr), city(ct), passportData(pd) {}

    Subscription::~Subscription() {}

    string Subscription::getLastName() const { return lastName; }
}
