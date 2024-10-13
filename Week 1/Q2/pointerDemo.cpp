#include <iostream>
#include <string>
using namespace std;

int main(){
    int value1 = 200000;
    int value2;
    int *ptr;
    ptr = &value1;
    cout<<"Ptr : "<<*ptr<<endl;
    value2 = *ptr;
    cout<<"value 2 : "<<value2<<endl; // i observe that value 2 = value 1
    cout<<"Address of value 1: "<<&value1<<endl;
    cout<<"Address stored in ptr: "<<ptr<<endl; //Yes, the value is the same
    ptr = &value2;
    *ptr += 2000;
    cout<<"value 1 : "<<value1<<endl;
    cout<<"value 2 : "<<value2<<endl; 
    /* value1 remains 200000 because after step (j),
     ptr was updated to point to value2. The operation *ptr += 2000 affects value2, not value1, 
     so value2 becomes 202000, and value1 remains unchanged. 
    */
    return 0;
}