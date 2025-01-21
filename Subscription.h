#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

namespace BillingSystem {

    class Subscription {
    private:
        std::string lastName;
        std::string firstName;
        std::string patronymic;
        std::string address;
        std::string city;
        std::string passportData;

        static int count;

    public:
        Subscription(const std::string& lastName, const std::string& firstName, const std::string& patronymic,
            const std::string& address, const std::string& city, const std::string& passportData);
        virtual ~Subscription();

        static int getCount();
        virtual void display() const;
        const std::string& getLastName() const;
        const std::string& getCity() const;
        void setCity(const std::string& newCity);

        bool operator==(const Subscription& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Subscription& sub);
    };
}
