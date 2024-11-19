//Calculates the value of a given integer raised to the power of a second integer  
//param a – the base integer (to be raised to a power).
//param n – the power
//pre: a > 0
//post: return the value of a raised to the nth power.
#include <iostream>
using namespace std;

long power (int a, int n){
    if (n == 0) {
        return 1;
    }
    return a * power(a, n - 1);
};

int main(){
    int result = power(3,4);
    cout<<"value: "<<result<<endl;
    return 0;
}
