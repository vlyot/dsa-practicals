#include <iostream>
using namespace std;
int search (int dataArray[], int arraySize, int target){
    for (int i = 0; i < arraySize; i++){
        if (dataArray[i] == target){
            cout<<"Item found at index "<<i<<endl;
            return i;
        }
        else{
            if (dataArray[i] > target){
                cout<<"Item not found "<<endl;
                return -1;
            }
        }
    }
    cout<<"Item not found "<<endl;
    return -1;
}

int main(){
    int arr[1000] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50};
    cout<<"Enter target number to search: ";
    int target = 0;
    cin>>target;
    int result = search(arr,1000,target);
    return 0;
}