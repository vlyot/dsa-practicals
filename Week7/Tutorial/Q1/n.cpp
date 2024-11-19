#include <iostream>
using namespace std;

// Recursive function to calculate the sum of the first n integers in an array
int sumOfFirstN(int arr[], int n) {
    // Base case: if n is 0, return 0 (no elements to add)
    if (n == 0) {
        return 0;
    }
    // Recursive case: add the nth element and call the function for the remaining elements
    return arr[n - 1] + sumOfFirstN(arr, n - 1);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 5; // Number of elements to sum

    int result = sumOfFirstN(numbers, n);
    cout << "The sum of the first " << n << " elements is: " << result << endl;

    return 0;
}
