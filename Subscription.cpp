
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

    std::string Subscription::getFirstName() const {
        return firstName;
    }

    std::string Subscription::getMiddleName() const {
        return middleName;
    }

    std::string Subscription::getAddress() const {
        return address;
    }

    std::string Subscription::getCity() const {
        return city;
    }

    std::string Subscription::getPassportData() const {
        return passportData;
    }

    void Subscription::setCity(const std::string& newCity) {
        city = newCity;
    }

    int Subscription::getCount() {
        return count;
    }

    std::ostream& operator<<(std::ostream& os, const Subscription& sub) {
        os << "Name: " << sub.lastName << " " << sub.firstName << " " << sub.middleName
            << ", Address: " << sub.address << ", City: " << sub.city << ", Passport Data: " << sub.passportData;
        return os;
    }

    bool Subscription::operator==(const Subscription& other) const {
        return this->lastName == other.lastName;
    }
}
