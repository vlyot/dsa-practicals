#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Get the maximum value in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) maxVal = max(maxVal, num);
    return maxVal;
}

// Perform counting sort on the basis of a significant digit
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences of digits
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    // Update count[i] to contain the position of the digit in the output array
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

// Radix Sort Function
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Main Function
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    cout << "Radix Sorted Array: ";
    for (int num : arr) cout << num << " ";
    return 0;
}
