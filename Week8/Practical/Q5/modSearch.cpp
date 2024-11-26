#include <iostream>
using namespace std;
static int comparisons = 0;
int binarySearch (int dataArray[], int arraySize, int target){
    int first = 0;
    int last = arraySize -1;
    while (first <= last){
        int mid = (first + last)/2;
        if (dataArray[mid] == target){
            cout<<"item found at index "<<mid<<endl;
            return mid;
        }
        else{
            if (target < dataArray[mid]){
                comparisons++;
                last = mid-1;
            }
            else{
                comparisons++;
                first = mid + 1;
            }
        }
    }
    cout<<"item not found"<<endl;
    return -1;
}
int search (int dataArray[], int arraySize, int start, int target){
    if (start > arraySize){
        return -1;
    }
    if (dataArray[start] == target){
        cout<<"Item found at index "<<start<<endl;
        return start;
    }
    if (dataArray[start] > target){
        cout<<"Item not found "<<endl;
        return -1;
    }
    comparisons++;
    return search (dataArray, arraySize, start+1,  target);
}
