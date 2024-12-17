#pragma once
#include "Subscription.h"

namespace BillingSystem {
    class InternationalCall : public Subscription {
    private:
        std::string country;
        std::string cityCall;
        int duration;
        double price;
        double totalAmount;
        int month, year;

    public:
        InternationalCall(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd,
            std::string cntry, std::string cityC, int dur, double p, double ta, int m, int y);

        void display() const override;
    };
}
