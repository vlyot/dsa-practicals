#include "List.h"
#include <iostream>
using namespace std;

// Constructor
List::List() {
    size = 0;  // Initialize size to 0
}

// List phone numbers in the list
void List::display() {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            cout << i+1 << ": " << numbers[i] << "\n";  // Display the index along with the number
        }
    } else {
        cout << "The list is empty." << endl;
    }
}

// Add phone numbers to the list
bool List::add(string number) {
    if (size < MAX_SIZE) {
        numbers[size] = number;    // Add to the end of the list
        size++;                    // Increase the size by 1
        return true;
    }
    return false;
}

// Remove a number at a specified position in the list
void List::remove(int index) {
    if (index >= 0 && index < size) {
        for (int pos = index; pos < size - 1; pos++) {
            numbers[pos] = numbers[pos + 1];  // Shift items left
        }
        size--;  // Decrease the size by 1
    } else {
        cout << "Invalid index!" << endl;
    }
}

// Search for a phone number by index
void List::search(int index) {
    if (index >= 0 && index < size) {
        cout << "Number at index " << index << ": " << numbers[index] << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}
