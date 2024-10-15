#include "List.h"  // header file
#include <iostream>
using namespace std;

void program();

int main(){
    List phoneNumbers;

    phoneNumbers.add("1234-5678-90");
    phoneNumbers.add("5678-1234-90");
    phoneNumbers.add("9999-5555-90");
    phoneNumbers.add("90");//short number for ease during testing/running program

    while (true){
        int option;
        program();
        cin>>option;
        string n;
        int nI;
        switch(option){
            case 1:
                phoneNumbers.display();
                break;
            case 2:
                cout<<"Add number"<<'\n'<<"Please enter number to add: ";
                cin>>n;
                cout<<endl;
                phoneNumbers.add(n);
                break;
            case 3:
                cout<<"Remove number"<<'\n'<<"Please enter index of number to remove: ";
                cin>>nI;
                cout<<endl;
                phoneNumbers.remove(nI);
                break;
            case 4:
                cout<<"Search list for number"<<'\n'<<"Please enter index of number to search for: ";
                cin>>nI;
                cout<<endl;
                phoneNumbers.search(nI);
                break;
            case 0:
                cout<<"Ending program."<<endl;
                return 0;

            default:
            cout<<"Invalid option! Please try another option"<<endl;
            break;
        }

    }
    return 0;
};

void program(){
    cout<<"----------- Main Menu ----------"<<endl;
    cout<<"[1] List the phone numbers"<<endl;
    cout<<"[2] Add a new contact"<<endl;
    cout<<"[3] Remove a contact  "<<endl;
    cout<<"[4] Search for a phone number "<<endl;
    cout<<"[0] Exit"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"Please enter an option: ";
}