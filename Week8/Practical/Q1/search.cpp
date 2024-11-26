#include <iostream>
using namespace std;
int search (int dataArray[], int arraySize, int target){
    for (int i = 0; i < arraySize; i++){
        if (dataArray[i] == target){
            return i;
        }
        else{
            if (dataArray[i] > target){
                return -1;
            }
        }
    }
    return -1;
}