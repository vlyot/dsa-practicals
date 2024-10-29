#include <iostream>
#include <vector>
#include <stack>
#include "stack.h"
using namespace std;

Stack::~Stack(){
    Node* current = topNode;  // Start at the top of the stack
    while (current != nullptr) {
        Node* temp = current;  // Store the current node
        current = current->next;  // Move to the next node
        delete temp;  // Delete the stored node
    }
    topNode = nullptr;
}

bool Stack::pop(ItemType &item){
    bool success = !isEmpty();
    if (success){
        Node* temp = topNode;
        item = temp->item; 
        topNode = topNode->next;
        delete temp;
    }
    return success;
}

void Stack::displayInOrder(){
    bool success = !isEmpty();
    if (success){
        Node* current = topNode;  // Start at the top of the stack
        while (current != nullptr) {
            cout<<current->item<<", ";  // Store the current node
            current = current->next;  // Move to the next node
        }
        cout<<endl;
    }
    else{
        cout<<"Error: Stack is empty"<<endl;
    }
}

void Stack::displayInOrderOfInsertion(){
    bool success = !isEmpty();
    if (success){
        vector<ItemType> ar;
        Node* current = topNode;  // Start at the top of the stack
        while (current != nullptr) {
            ar.push_back(current->item);  // Store the current node
            current = current->next;  // Move to the next node
        }
        for (int i = ar.size() - 1; i >= 0; --i) {
            cout << ar[i] << ", ";
        }
        cout << endl;  
    }
    else{
        cout<<"Error: Stack is empty"<<endl;
    }
}

string Stack::reverse(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }
    string output;
    while (!st.empty()) {
        output += st.top(); 
        st.pop();           
    }

    return output;
}