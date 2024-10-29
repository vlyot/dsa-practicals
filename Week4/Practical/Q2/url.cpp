#include <iostream>
#include <string>
#include "stack.h"
using namespace std;
int main()
{
    Stack back_stack;
    int url = 0; 
    string temp;
    while (temp != "0")
    {
        cout << "[1] Visit URL\n[2] Back\n[0] Exit\nYour Choice: ";
        cin >> temp;
        if (temp == "0"){
            break;
        }
        if (temp == "1"){
            url++;
            back_stack.push(url);
            cout<<"visited url "<<url<<". "<<endl;
        }
        if (temp == "2"){
            back_stack.pop();
            url--;
            cout<<"returned back to url "<<url<<endl;

        }
    }
    return 0;
}
