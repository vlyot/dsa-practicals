#include <iostream>
using namespace std;
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
    return search (dataArray, arraySize, start+1,  target);
}

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr,n,0,8);

    return 0;
}