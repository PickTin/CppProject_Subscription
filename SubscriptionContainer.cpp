using namespace std;
#include "SubscriptionContainer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Failed to open file for loading.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            std::getline(iss, type, ','); 
            if (type == "CityCall") {
                std::string lastName, firstName, middleName, address, city, passportData;
                double tariff;
                int duration;
                std::getline(iss, lastName, ',');
                std::getline(iss, firstName, ',');
                std::getline(iss, middleName, ',');
                std::getline(iss, address, ',');
                std::getline(iss, city, ',');
                std::getline(iss, passportData, ',');
                iss >> tariff >> duration;

                
                addSubscription(new CityCall(lastName, firstName, middleName, address, city, passportData, tariff, duration));
            }
            else if (type == "InternationalCall") {
                std::string lastName, firstName, middleName, address, city, passportData, country, cityCall;
                double price, totalAmount;
                int duration, month, year;
                std::getline(iss, lastName, ',');
                std::getline(iss, firstName, ',');
                std::getline(iss, middleName, ',');
                std::getline(iss, address, ',');
                std::getline(iss, city, ',');
                std::getline(iss, passportData, ',');
                std::getline(iss, country, ',');
                std::getline(iss, cityCall, ',');
                iss >> duration >> price >> totalAmount >> month >> year;

               
                addSubscription(new InternationalCall(lastName, firstName, middleName, address, city, passportData, country, cityCall, duration, price, totalAmount, month, year));
            }
            else if (type == "InternetConnection") {
                std::string lastName, firstName, middleName, address, city, passportData, connectionName;
                int dataVolume, month, year;
                double totalAmount;
                std::getline(iss, lastName, ',');
                std::getline(iss, firstName, ',');
                std::getline(iss, middleName, ',');
                std::getline(iss, address, ',');
                std::getline(iss, city, ',');
                std::getline(iss, passportData, ',');
                std::getline(iss, connectionName, ',');
                iss >> dataVolume >> totalAmount >> month >> year;

                
                addSubscription(new InternetConnection(lastName, firstName, middleName, address, city, passportData, connectionName, dataVolume, totalAmount, month, year));
            }
            else {
                cout << "Unknown subscription type: " << type << std::endl;

                continue;
            }
        }

        file.close();
    }


    void SubscriptionContainer::sortByLastName() {
        std::sort(subscriptions.begin(), subscriptions.end(),
            [](Subscription* a, Subscription* b) { return a->getLastName() < b->getLastName(); });
    }
}