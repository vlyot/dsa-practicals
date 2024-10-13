#include <iostream>
#include <string>
using namespace std;
void changevalue(int x, int *y){
    x += 10;
    *y += 10;
}
int main(){
    int x = 30;
    int y;
    y = x;
    changevalue(x,&y);
    cout<< "x: "<<x<<", y: "<<y<<endl;
    return 0;
}

/* PART D ANSWER:
No, they are not the same. x in main is passed by value to the function,
so the changes inside the function do not affect the original x in main.
y in main is passed by reference (as a pointer),
so changes made to *y in changeValue directly modify y in main.
*/