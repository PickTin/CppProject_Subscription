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
            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; 
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

    void SubscriptionContainer::saveToFile(const string& filename) const {
        ofstream file(filename);

        for (auto sub : subscriptions) {
            if (dynamic_cast<CityCall*>(sub)) {
                file << "CityCall\n";
                file << sub->getLastName() << "\n";
                file << sub->getFirstName() << "\n";
                file << sub->getMiddleName() << "\n";
                file << sub->getAddress() << "\n";
                file << sub->getCity() << "\n";
                file << sub->getPassportData() << "\n";
                file << dynamic_cast<CityCall*>(sub)->getTariff() << "\n";
                file << dynamic_cast<CityCall*>(sub)->getDuration() << "\n";
            }
            else if (dynamic_cast<InternetConnection*>(sub)) {
                file << "InternetConnection\n";
                file << sub->getLastName() << "\n";
                file << sub->getFirstName() << "\n";
                file << sub->getMiddleName() << "\n";
                file << sub->getAddress() << "\n";
                file << sub->getCity() << "\n";
                file << sub->getPassportData() << "\n";
                file << dynamic_cast<InternetConnection*>(sub)->getConnectionName() << "\n";
                file << dynamic_cast<InternetConnection*>(sub)->getDataVolume() << "\n";
                file << dynamic_cast<InternetConnection*>(sub)->getTotalAmount() << "\n";
                file << dynamic_cast<InternetConnection*>(sub)->getMonth() << "\n";
                file << dynamic_cast<InternetConnection*>(sub)->getYear() << "\n";
            }
            else if (dynamic_cast<InternationalCall*>(sub)) {
                file << "InternationalCall\n";
                file << sub->getLastName() << "\n";
                file << sub->getFirstName() << "\n";
                file << sub->getMiddleName() << "\n";
                file << sub->getAddress() << "\n";
                file << sub->getCity() << "\n";
                file << sub->getPassportData() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getCountry() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getCityCall() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getDuration() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getPrice() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getTotalAmount() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getMonth() << "\n";
                file << dynamic_cast<InternationalCall*>(sub)->getYear() << "\n";
            }
        }
    }

    void SubscriptionContainer::loadFromFile(const string& filename) {
        ifstream file(filename);
        string type;

        while (getline(file, type)) {
            if (type == "CityCall") {
                string lastName, firstName, middleName, address, city, passportData;
                double tariff;
                int duration;
                getline(file, lastName);
                getline(file, firstName);
                getline(file, middleName);
                getline(file, address);
                getline(file, city);
                getline(file, passportData);
                file >> tariff >> duration;
                file.ignore();  
                addSubscription(new CityCall(lastName, firstName, middleName, address, city, passportData, tariff, duration));
            }
            else if (type == "InternetConnection") {
                string lastName, firstName, middleName, address, city, passportData, connectionName;
                int dataVolume;
                double totalAmount;
                int month, year;
                getline(file, lastName);
                getline(file, firstName);
                getline(file, middleName);
                getline(file, address);
                getline(file, city);
                getline(file, passportData);
                getline(file, connectionName);
                file >> dataVolume >> totalAmount >> month >> year;
                file.ignore();
                addSubscription(new InternetConnection(lastName, firstName, middleName, address, city, passportData, connectionName, dataVolume, totalAmount, month, year));
            }
            else if (type == "InternationalCall") {
                string lastName, firstName, middleName, address, city, passportData, country, cityCall;
                int duration;
                double price, totalAmount;
                int month, year;
                getline(file, lastName);
                getline(file, firstName);
                getline(file, middleName);
                getline(file, address);
                getline(file, city);
                getline(file, passportData);
                getline(file, country);
                getline(file, cityCall);
                file >> duration >> price >> totalAmount >> month >> year;
                file.ignore();
                addSubscription(new InternationalCall(lastName, firstName, middleName, address, city, passportData, country, cityCall, duration, price, totalAmount, month, year));
            }
            else {
                cout << "Unknown subscription type: " << type << endl;
                file.ignore(numeric_limits<streamsize>::max(), '\n');  
            }
        }
    }


    void SubscriptionContainer::sortByLastName() {
        std::sort(subscriptions.begin(), subscriptions.end(),
            [](Subscription* a, Subscription* b) { return a->getLastName() < b->getLastName(); });
    }
}