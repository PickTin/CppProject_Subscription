#include "SubscriptionContainer.h"
#include "InternationalCall.h"
#include "CityCall.h"
#include "InternetConnection.h"

using namespace BillingSystem;

int main() {
    SubscriptionContainer container;

    container.addSubscription(new InternationalCall("Smith", "John", "A.", "Street 1", "New York", "AA12345",
        "USA", "NY", 10, 0.5, 5.0, 5, 2024));

    container.addSubscription(new CityCall("Doe", "Jane", "B.", "Street 2", "Chicago", "BB67890",
        0.1, 50, 5.0, 6, 2024));

    container.addSubscription(new InternetConnection("Brown", "Tom", "C.", "Street 3", "Los Angeles", "CC98765",
        "Fiber", 1000, 20.0, 7, 2024));

    container.displayAll();
}
