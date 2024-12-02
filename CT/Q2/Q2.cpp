// Q2.cpp 
#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

void displayMenu();             // function to display main menu

void compose(Stack& s);

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
    cout<<"Option 1 : Compose"<<endl;
    string c;
    cin>>c;
    for (char p : c){
        s.push(p);
    }
    s.printInOrderOfInsertion();
}

// 2(b)
void undo(Stack& s)
{

    while (true){
        if (s.isEmpty()){
            cout<<"text is empty"<<endl;
            break;
        }
        s.printInOrderOfInsertion();
        cout<<endl;
        cout<<"Enter 1 to undo, 0 to quit: ";
        int option = 3;
        cin>>option;
        if (option == 0){
            break;
        }
        s.pop();
    }


}
void clear(Stack& s){
    while (!s.isEmpty()){
        s.pop();
    }

}