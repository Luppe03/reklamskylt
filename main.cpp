#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

struct Message {
    string text;
    string effect;
};

struct Customer {
    string name;
    int weight;
    vector<Message> messages;
};

int weightedRandomCustomer(const vector<Customer>& customers, int lastCustomerIndex) {
    int totalWeight = 0;

    for (int i = 0; i < (int)customers.size(); i++) {
        if (i != lastCustomerIndex) {
            totalWeight += customers[i].weight;
        }
    }

    int randomValue = rand() % totalWeight;

    for (int i = 0; i < (int)customers.size(); i++) {
        if (i == lastCustomerIndex) {
            continue;
        }

        if (randomValue < customers[i].weight) {
            return i;
        }

        randomValue -= customers[i].weight;
    }

    return 0;
}

Message getRandomMessage(const Customer& customer) {
    int index = rand() % customer.messages.size();
    return customer.messages[index];
}

void displayMessage(const Customer& customer, const Message& message) {
    cout << "-----------------------------" << endl;
    cout << "Kund: " << customer.name << endl;
    cout << "Meddelande: " << message.text << endl;
    cout << "Visningstyp: " << message.effect << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    srand(time(0));

    vector<Customer> customers = {
        {
            "Hederlige Harrys Bilar",
            5000,
            {
                {"Kop bil hos Harry", "scroll"},
                {"En god bilaffar (for Harry!)", "text"},
                {"Hederlige Harrys Bilar", "blink"}
            }
        },
        {
            "Farmor Ankas Pajer AB",
            3000,
            {
                {"Kop paj hos Farmor Anka", "scroll"},
                {"Skynda innan Marten atit alla pajer", "text"}
            }
        },
        {
            "Svarte Petters Svartbyggen",
            1500,
            {
                {"Lat Petter bygga at dig", "scroll"},
                {"Bygga svart? Ring Petter", "text"}
            }
        },
        {
            "Langbens detektivbyra",
            4000,
            {
                {"Mysterier? Ring Langben", "text"},
                {"Langben fixar biffen", "text"}
            }
        },
        {
            "IOT:s Reklambyra",
            1000,
            {
                {"Synas har? IOT:s Reklambyra", "text"}
            }
        }
    };

    int lastCustomerIndex = -1;

    while (true) {
        int customerIndex = weightedRandomCustomer(customers, lastCustomerIndex);
        Customer currentCustomer = customers[customerIndex];
        Message currentMessage;

        if (currentCustomer.name == "Svarte Petters Svartbyggen") {
            time_t now = time(0);
            tm* localTime = localtime(&now);

            if (localTime->tm_min % 2 == 0) {
                currentMessage = currentCustomer.messages[0];
            } else {
                currentMessage = currentCustomer.messages[1];
            }
        } else {
            currentMessage = getRandomMessage(currentCustomer);
        }

        displayMessage(currentCustomer, currentMessage);
        lastCustomerIndex = customerIndex;

        this_thread::sleep_for(chrono::seconds(20));
    }

    return 0;
}