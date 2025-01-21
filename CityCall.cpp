#include "CityCall.h"

namespace BillingSystem {

    CityCall::CityCall(const std::string& lastName, const std::string& firstName, const std::string& patronymic,
        const std::string& address, const std::string& city, const std::string& passportData,
        double tariff, double duration, double payment, int month, int year)
        : Subscription(lastName, firstName, patronymic, address, city, passportData),
        tariff(tariff), duration(duration), payment(payment), month(month), year(year) {}

    void CityCall::display() const {
        Subscription::display();
        std::cout << "Tariff: " << tariff << ", Duration: " << duration << " minutes, Payment: " << payment
            << ", Date: " << month << "/" << year << std::endl;
    }

    double CityCall::getPayment() const { return payment; }
    void CityCall::setPayment(double newPayment) { payment = newPayment; }
    double CityCall::getDuration() const { return duration; }
    void CityCall::setDuration(double newDuration) { duration = newDuration; }
    int CityCall::getMonth() const { return month; }
    int CityCall::getYear() const { return year; }

}
