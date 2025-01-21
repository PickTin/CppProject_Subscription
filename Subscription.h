#pragma once
#include <string>
#include <iostream>

namespace BillingSystem {
    class Subscription {
    protected:
        std::string lastName;
        std::string firstName;
        std::string middleName;
        std::string address;
        std::string city;
        std::string passportData;

        static int count;

    public:
        Subscription(std::string ln, std::string fn, std::string mn, std::string addr, std::string ct, std::string pd);
        virtual ~Subscription();

        virtual void display() const = 0;

        std::string getLastName() const;
        void setCity(const std::string& newCity);

        static int getCount();


        friend std::ostream& operator<<(std::ostream& os, const Subscription& sub);
        bool operator==(const Subscription& other) const;
    };
}