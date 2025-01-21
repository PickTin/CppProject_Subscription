#pragma once
#include "Subscription.h"

namespace BillingSystem {
    class InternetConnection : public Subscription {
    private:
        std::string connectionName;
        int dataVolume;
        double totalAmount;
        int month, year;

    public:
        InternetConnection(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd, std::string cn, int dv, double ta, int m, int y);
        void display() const override;

        std::string getConnectionName() const;
        int getDataVolume() const;
        double getTotalAmount() const;
        int getMonth() const;
        int getYear() const;
    };
}
