//return the maximum value in an array of integers
//param array – the array in concern
//param start – start index of the array
//param end   – last index of the array
#include <iostream>
using namespace std;

int maxArray(int array[], int start, int end){
    if (start == end){
        return array[start];
    }

    // Recursive case: find the maximum in the rest of the array
    int maxInRest = maxArray(array, start + 1, end);

    // Compare current element to the maximum of the rest and return the larger value
    return (array[start] > maxInRest) ? array[start] : maxInRest;
};
int main() {
    int arr[] = {10, 20, 30, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int maxVal = maxArray(arr, 0, n - 1);
    cout << "The maximum value in the array is: " << maxVal << endl;

    return 0;
}