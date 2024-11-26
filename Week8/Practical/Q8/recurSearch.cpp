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