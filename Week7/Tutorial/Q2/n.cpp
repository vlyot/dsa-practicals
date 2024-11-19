#include <iostream>
using namespace std;

// Recursive function to calculate the sum of the first n integers in an array
int sum(int n) {
    if (n == 0){
        return 0;
    }
    else{
        return n + sum(n-1);
    }
}

int main() {
    int n = 5; // Number of elements to sum

    int result = sum(n);
    cout << "sum: "<< result << endl;

    return 0;
}
