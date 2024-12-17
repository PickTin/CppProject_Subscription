#pragma once
#include "Subscription.h"
#include <vector>

namespace BillingSystem {
    class SubscriptionContainer {
    private:
        std::vector<Subscription*> subscriptions;

    public:
        ~SubscriptionContainer();
        void addSubscription(Subscription* sub);
        void displayAll() const;
    };
}
