#include <iostream>
using namespace std;
int binarySearch (int dataArray[], int arraySize, int target){
    int first = 0;
    int last = arraySize -1;
    while (first < last){
        int mid = (first + last)/2;
        if (dataArray[mid] == target){
            cout<<"item found at index "<<mid<<endl;
            return mid;
        }
        else{
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
}