#include <iostream>
#include <vector>
using namespace std;

// Function for Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Find the index of the smallest element in the remaining array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

// Main Function
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    
    cout << "Selection Sorted Array: ";
    for (int num : arr) cout << num << " ";
    return 0;
}
