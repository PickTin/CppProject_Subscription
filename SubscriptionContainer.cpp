#include "SubscriptionContainer.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace BillingSystem {
    SubscriptionContainer::~SubscriptionContainer() {
        for (auto sub : subscriptions)
            delete sub;
    }

    void SubscriptionContainer::addSubscription(Subscription* sub) {
        subscriptions.push_back(sub);
    }

    void SubscriptionContainer::displayAll() const {
        for (const auto& sub : subscriptions) {
            sub->display();
        }
    }
}
