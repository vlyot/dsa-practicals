#include <iostream>
using namespace std;
static int comparisons = 0;
int binarySearch (int dataArray[], int arraySize, int target){
    int first = 0;
    int last = arraySize -1;

    while (first <= last){
        comparisons++;
        int mid = (first + last)/2;

        if (dataArray[mid] == target){
            cout<<"item found at index "<<mid<<endl;
            return mid;
        }

        comparisons++;
        if (target < dataArray[mid]){
                
            last = mid-1;
        }
        else{
                
            first = mid + 1;
        }
    }
    cout<<"item not found"<<endl;
    return -1;
}
int search (int dataArray[], int arraySize, int start, int target){
    if (start > arraySize){
        return -1;
    }
    comparisons++;
    if (dataArray[start] == target){
        cout<<"Item found at index "<<start<<endl;
        return start;
    }
    if (dataArray[start] > target){
        cout<<"Item not found "<<endl;
        return -1;
    }
    return search (dataArray, arraySize, start+1,  target);
}



int main(){
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = 2 * (i + 1);
    }

    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int target = 2000;
    
    comparisons = 0; // Reset comparisons count
    int idx1 = search(arr, arraySize, 0, target);
    cout << "Sequential Search comparisons: " << comparisons << endl;

    // Binary Search
    comparisons = 0; // Reset comparisons count
    int idx2 = binarySearch(arr, arraySize, target);
    cout << "Binary Search comparisons: " << comparisons << endl;
    cout<<"============================================"<<endl;
    return 0;
}