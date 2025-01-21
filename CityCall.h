#pragma once
#include "Subscription.h"

namespace BillingSystem {
    class CityCall : public Subscription {
    private:
        double tariff;
        int duration;

    public:
        CityCall(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, double t, int d);

        void display() const override;
    };
}