// Q2.cpp 
#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

void displayMenu();             // function to display main menu
void compose(Stack& s);         // function to enter the text
void undo(Stack& s);            // function to undo changes 
void clear(Stack& s);           // function to clear the text

int main()
{
    int option = 1;
    Stack s;

    while (option != 0)
    {
        displayMenu();
        cin >> option;
        if (option == 1)
            compose(s);
        else
            if (option == 2)
                undo(s);
            else
                if (option == 3)
                    clear(s);
                else
                    cout << "Invalid option! Please try again." << endl;
    }

    return 0;
}

// function to display main menu
void displayMenu()
{
    cout << endl;
    cout << "Main Menu           " << endl;
    cout << "--------------------" << endl;
    cout << "[1] Compose         " << endl;
    cout << "[2] Undo            " << endl;
    cout << "[3] Clear           " << endl;
    cout << "[0] Exit            " << endl;
    cout << "--------------------" << endl;
    cout << "Enter your option: ";
}

// 2(a)
void compose(Stack& s)
{
    string input;
    cout << "Enter a string: ";
    cin.ignore(); // Clear the newline from previous input
    getline(cin, input); // Reads the entire line, including spaces

    for (char c : input) {
        s.push(c); // Push each character onto the stack
    }
    cout<<input<<endl;

}

// 2(b)
void undo(Stack& s)
{
    s.pop();
    s.printInOrderOfInsertion();
}

// 2(c)
void clear(Stack& s)
{
        while (!s.isEmpty()){
        s.pop();
    }

}
