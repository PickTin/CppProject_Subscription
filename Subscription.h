#pragma once
#include <string>

namespace BillingSystem {
    class Subscription {
    protected:
        std::string lastName;
        std::string firstName;
        std::string middleName;
        std::string address;
        std::string city;
        std::string passportData;

    public:
        Subscription(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd);
        virtual ~Subscription();

        virtual void display() const = 0;

        std::string getLastName() const;
    };
}
