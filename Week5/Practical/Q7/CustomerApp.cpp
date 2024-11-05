#include <string>
#include <iostream>
#include <random>
#include "Queue.h"
#include "Customer.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    Queue q;
    int totalCustomersServed = 0;
    int totalTime = 0;

    // Simulate 10 minutes
    for (int time = 0; time < 10; ++time) {
        // Dequeue a customer if there is one
        if (!q.isEmpty()) {
            Customer servedCustomer;
            q.dequeue(servedCustomer);
            int waitTime = time - servedCustomer.getQueueNum();
            cout << "Customer " << servedCustomer.getName() << " was served in " << waitTime << " min(s)" << endl;
            totalTime += waitTime;
            totalCustomersServed++;
        }

        // Determine how many customers arrive (0, 1, or 2)
        int k = rand() % 4; // Generate a random number between 0 and 3
        for (int i = 0; i < k; ++i) {
            string name;
            cout << "Enter Customer name: ";
            cin >> name;
            Customer newCustomer(name, time);
            q.enqueue(newCustomer);
        }
    }

    // Calculate and display average time to be served
    if (totalCustomersServed > 0) {
        double averageTime = static_cast<double>(totalTime) / totalCustomersServed;
        cout << "In this 10-min period, the average time to be served = " << averageTime << " mins" << endl;
    } else {
        cout << "No customers were served during this period." << endl;
    }

    return 0;
}
