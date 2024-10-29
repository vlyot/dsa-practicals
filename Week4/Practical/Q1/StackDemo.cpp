#include <iostream>
#include <vector>
#include <array>
#include "stack.h"
using namespace std;

int main(){
    ItemType item = 0;
    Stack* s = new Stack;
    s->push(3);
    s->push(4);
    s->getTop(item);
    s->displayInOrderOfInsertion();
    s->pop();
    s->displayInOrderOfInsertion();

    return 0;
}