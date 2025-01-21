#include "SubscriptionContainer.h"

namespace BillingSystem {

    SubscriptionContainer::~SubscriptionContainer() {
        for (auto* sub : subscriptions) {
            delete sub;
        }
    }

    void SubscriptionContainer::addSubscription(Subscription* sub) {
        if (!sub) throw std::invalid_argument("Null subscription cannot be added");
        subscriptions.push_back(sub);
    }

    void SubscriptionContainer::removeSubscriptionByLastName(const std::string& lastName) {
        auto it = std::remove_if(subscriptions.begin(), subscriptions.end(),
            [&lastName](Subscription* sub) { return sub->getLastName() == lastName; });
        if (it != subscriptions.end()) {
            delete* it;
            subscriptions.erase(it);
        }
        else {
            throw std::runtime_error("Subscription not found");
        }
    }

    Subscription* SubscriptionContainer::findSubscriptionByLastName(const std::string& lastName) {
        for (auto* sub : subscriptions) {
            if (sub->getLastName() == lastName) {
                return sub;
            }
        }
        throw std::runtime_error("Subscription not found");
    }

    void SubscriptionContainer::editSubscriptionByLastName(const std::string& lastName, const std::string& newCity) {
        Subscription* sub = findSubscriptionByLastName(lastName);
        if (sub) {
            sub->setCity(newCity);
        }
        else {
            throw std::runtime_error("Subscription not found");
        }
    }

    void SubscriptionContainer::sortByLastName() {
        std::sort(subscriptions.begin(), subscriptions.end(),
            [](Subscription* a, Subscription* b) { return a->getLastName() < b->getLastName(); });
    }

    void SubscriptionContainer::displayAll() const {
        for (const auto* sub : subscriptions) {
            sub->display();
        }
    }

}
