#include<string>
#include<iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;
bool recognisePalindromes(string str);

int main(){
    string input;
    cout<<"Enter string of characters to enter: ";
    cin>>input;
    cout<<endl;

    if (recognisePalindromes(input)) {
        cout << "The input string is a palindrome." << endl;
    } else {
        cout << "The input string is not a palindrome." << endl;
    }
    return 0;
}


bool recognisePalindromes(string str) {
    Queue aQueue;  // Create an empty queue
    Stack aStack;  // Create an empty stack

    // Step 1: Insert each character of the string into both the queue and the stack
    int length = str.length();
    for (int i = 0; i < length; i++) {
        char nextChar = str[i];
        aQueue.enqueue(nextChar);  // Add character to queue
        aStack.push(nextChar);     // Add character to stack
    }

    // Step 2: Compare the queue characters with the stack characters
    bool charactersAreEqual = true;
    while (!aQueue.isEmpty() && charactersAreEqual) {
        char queueFront, stackTop;

        // Retrieve the front item from the queue and the top item from the stack
        aQueue.getFront(queueFront);
        aStack.getTop(stackTop);

        // Compare the two characters
        if (queueFront == stackTop) {
            aQueue.dequeue();  // Remove front item from queue
            aStack.pop();      // Remove top item from stack
        } else {
            charactersAreEqual = false;  // Characters do not match, so not a palindrome
        }
    }

    // Return whether all characters matched
    return charactersAreEqual;
}