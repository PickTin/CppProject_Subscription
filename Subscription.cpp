#include "Subscription.h"

namespace BillingSystem {
    int Subscription::count = 0;

    Subscription::Subscription(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd)
        : lastName(ln), firstName(fn), middleName(mn), address(addr), city(ct), passportData(pd) {
        count++;
    }

    Subscription::~Subscription() {
        count--;
    }

    std::string Subscription::getLastName() const {
        return lastName;
    }

    void Subscription::setCity(const std::string& newCity) {
        city = newCity;
    }

    int Subscription::getCount() {
        return count;
    }

    std::ostream& operator<<(std::ostream& os, const Subscription& sub) {
        os << "Name: " << sub.lastName << " " << sub.firstName << " " << sub.middleName
            << ", Address: " << sub.address << ", City: " << sub.city;
        return os;
    }

    bool Subscription::operator==(const Subscription& other) const {
        return this->lastName == other.lastName;
    }
}
