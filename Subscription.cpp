#include "Subscription.h"

namespace BillingSystem {

    int Subscription::count = 0;

    Subscription::Subscription(const std::string& lastName, const std::string& firstName, const std::string& patronymic,
        const std::string& address, const std::string& city, const std::string& passportData)
        : lastName(lastName), firstName(firstName), patronymic(patronymic),
        address(address), city(city), passportData(passportData) {
        if (lastName.empty() || city.empty()) throw std::invalid_argument("Invalid input data");
        ++count;
    }

    Subscription::~Subscription() { --count; }

    int Subscription::getCount() { return count; }

    void Subscription::display() const {
        std::cout << "Last Name: " << lastName << ", First Name: " << firstName << ", Patronymic: " << patronymic
            << ", Address: " << address << ", City: " << city << ", Passport: " << passportData << std::endl;
    }

    const std::string& Subscription::getLastName() const { return lastName; }

    const std::string& Subscription::getCity() const { return city; }

    void Subscription::setCity(const std::string& newCity) { city = newCity; }

    bool Subscription::operator==(const Subscription& other) const { return lastName == other.lastName; }

    std::ostream& operator<<(std::ostream& os, const Subscription& sub) {
        os << sub.lastName << " " << sub.firstName << " " << sub.patronymic << " " << sub.address << " "
            << sub.city << " " << sub.passportData;
        return os;
    }
}
