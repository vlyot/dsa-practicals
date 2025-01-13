#include <iostream>
#include <vector>
using namespace std;

// Function for Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element to be placed correctly
        int j = i - 1;

        // Shift larger elements one position to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the current element in the correct position
    }
}

// Main Function
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    insertionSort(arr);
    
    cout << "Insertion Sorted Array: ";
    for (int num : arr) cout << num << " ";
    return 0;
}
