#pragma once
#include "Subscription.h"
#include <vector>
#include <algorithm>

namespace BillingSystem {

    class SubscriptionContainer {
    private:
        std::vector<Subscription*> subscriptions;

    public:
        ~SubscriptionContainer();
        void addSubscription(Subscription* sub);
        void removeSubscriptionByLastName(const std::string& lastName);
        Subscription* findSubscriptionByLastName(const std::string& lastName);
        void editSubscriptionByLastName(const std::string& lastName, const std::string& newCity);
        void sortByLastName();
        void displayAll() const;
    };
}
