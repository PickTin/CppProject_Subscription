#pragma once
#include "Subscription.h"

namespace BillingSystem {

    class CityCall : public Subscription {
    private:
        double tariff;
        double duration;
        double payment;
        int month;
        int year;

    public:
        CityCall(const std::string& lastName, const std::string& firstName, const std::string& patronymic,
            const std::string& address, const std::string& city, const std::string& passportData,
            double tariff, double duration, double payment, int month, int year);

        virtual void display() const override;
        double getPayment() const;
        void setPayment(double newPayment);
        double getDuration() const;
        void setDuration(double newDuration);
        int getMonth() const;
        int getYear() const;
    };

}
