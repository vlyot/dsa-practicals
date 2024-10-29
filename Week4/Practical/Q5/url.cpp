#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main() {
    Stack back_stack;  // Stack to keep track of URLs visited
    Stack forward_stack;  // Stack to keep track of forward URLs

    ItemType currentUrl = 0; 
    string temp;

    while (true) {
        cout << "[1] Visit URL\n[2] Back\n[3] Go Forward\n[0] Exit\nYour Choice: ";
        cin >> temp;

        if (temp == "0") {
            break;  // Exit the loop if user chooses 0
        }

        if (temp == "1") {
            // Visit a new URL
            currentUrl++;
            back_stack.push(currentUrl);  // Push the current URL to the back stack
            cout << "Visited URL " << currentUrl << "." << endl;

            // Clear the forward stack, since we are visiting a new URL
            while (!forward_stack.isEmpty()) {
                forward_stack.pop();
            }
        }

        if (temp == "2") {
            // Go back to the previous URL
            if (!back_stack.isEmpty()) {
                back_stack.pop(currentUrl);  // Pop the current URL from the back stack
                forward_stack.push(currentUrl);  // Push the current URL to the forward stack

                if (!back_stack.isEmpty()) {
                    back_stack.getTop(currentUrl);  // Set the current URL to the new top of the back stack
                    cout << "Returned back to URL " << currentUrl << endl;
                } else {
                    currentUrl = 0;  // Set to initial state if no URL is left in the back stack
                    cout << "Returned to the initial state (no previous URL)." << endl;
                }
            } else {
                cout << "No previous URL to return to!" << endl;
            }
        }

        if (temp == "3") {
            // Go forward to the next URL
            if (!forward_stack.isEmpty()) {
                forward_stack.pop(currentUrl);  // Pop the forward stack to get the next URL
                back_stack.push(currentUrl);  // Push the current URL back to the back stack

                cout << "Went forward to URL " << currentUrl << "." << endl;
            } else {
                cout << "Error: There are no URLs after the current URL." << endl;
            }
        }
    }

    return 0;
}
