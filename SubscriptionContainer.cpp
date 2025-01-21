#include "SubscriptionContainer.h"

namespace BillingSystem {
    SubscriptionContainer::~SubscriptionContainer() {
        for (auto sub : subscriptions) delete sub;
    }

    void SubscriptionContainer::addSubscription(Subscription* sub) {
        subscriptions.push_back(sub);
    }

    void SubscriptionContainer::displayAll() const {
        for (auto sub : subscriptions) {
            sub->display();
        }
    }

    void SubscriptionContainer::removeSubscriptionByLastName(const std::string& lastName) {
        auto it = std::remove_if(subscriptions.begin(), subscriptions.end(),
            [&lastName](Subscription* sub) { return sub->getLastName() == lastName; });

        if (it != subscriptions.end()) {
            delete* it;
            subscriptions.erase(it, subscriptions.end());
        }
    }

    void SubscriptionContainer::editSubscription(const std::string& lastName) {
        Subscription* sub = findSubscriptionByLastName(lastName);
        if (sub) {
            std::string newCity;
            std::cout << "Enter new city: ";
            std::cin >> newCity;
            sub->setCity(newCity);
        }
    }

    Subscription* SubscriptionContainer::findSubscriptionByLastName(const std::string& lastName) {
        for (auto sub : subscriptions) {
            if (sub->getLastName() == lastName) return sub;
        }
        return nullptr;
    }

    void SubscriptionContainer::saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        for (auto sub : subscriptions) {
            file << *sub << "\n";
        }
    }

    void SubscriptionContainer::loadFromFile(const std::string& filename) {
        std::cout << "File loaded (parsing not implemented yet).\n";
    }

    void SubscriptionContainer::sortByLastName() {
        std::sort(subscriptions.begin(), subscriptions.end(),
            [](Subscription* a, Subscription* b) { return a->getLastName() < b->getLastName(); });
    }
}