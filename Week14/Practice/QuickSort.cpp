#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort Function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main Function
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Quick Sorted Array: ";
    for (int num : arr) cout << num << " ";
    return 0;
}
