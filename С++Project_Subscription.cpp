#include "CityCall.h"
#include "SubscriptionContainer.h"
#include "Subscription.h"
#include <iostream>
#include <iomanip>

using namespace BillingSystem;
using namespace std;

void printMenu() {
    cout << "\n--- Subscription Management ---\n";
    cout << "1. Add Subscription\n";
    cout << "2. Remove Subscription by Last Name\n";
    cout << "3. Edit Subscription\n";
    cout << "4. View All Subscriptions\n";
    cout << "5. Sort Subscriptions by Last Name\n";
    cout << "6. Save to File\n";
    cout << "7. Load from File\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    SubscriptionContainer container;

    while (true) {
        printMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            string lastName, firstName, middleName, address, city, passportData;
            double tariff;
            int duration;

            cout << "Enter Last Name: ";
            cin >> lastName;
            cout << "Enter First Name: ";
            cin >> firstName;
            cout << "Enter Middle Name: ";
            cin >> middleName;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter City: ";
            cin >> city;
            cout << "Enter Passport Data: ";
            cin >> passportData;
            cout << "Enter Tariff: ";
            cin >> tariff;
            cout << "Enter Duration (minutes): ";
            cin >> duration;

            container.addSubscription(new CityCall(lastName, firstName, middleName, address, city, passportData, tariff, duration));
        }
        else if (choice == 2) {
            string lastName;
            cout << "Enter Last Name to Remove: ";
            cin >> lastName;
            container.removeSubscriptionByLastName(lastName);
        }
        else if (choice == 3) {
            string lastName;
            cout << "Enter Last Name to Edit: ";
            cin >> lastName;
            container.editSubscription(lastName);
        }
        else if (choice == 4) {
            container.displayAll();
        }
        else if (choice == 5) {
            container.sortByLastName();
        }
        else if (choice == 6) {
            container.saveToFile("subscriptions.txt");
        }
        else if (choice == 7) {
            container.loadFromFile("subscriptions.txt");
        }
        else if (choice == 8) {
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}