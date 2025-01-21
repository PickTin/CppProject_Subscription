#pragma once
#include "Subscription.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include "CityCall.h"
#include "InternationalCall.h"
#include "InternetConnection.h"

namespace BillingSystem {
    class SubscriptionContainer {
    private:
        std::vector<Subscription*> subscriptions;

    public:
        ~SubscriptionContainer();

        void addSubscription(Subscription* sub);
        void displayAll() const;

        void removeSubscriptionByLastName(const std::string& lastName);
        void editSubscription(const std::string& lastName);
        Subscription* findSubscriptionByLastName(const std::string& lastName);

        void saveToFile(const std::string& filename) const;
        void loadFromFile(const std::string& filename);

        void sortByLastName();
    };
}