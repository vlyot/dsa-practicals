#include <iostream>
using namespace std;

int binarySearch (int dataArray[], int first, int last, int target){
    if (first > last){
        cout<<"item not in array"<<endl;
        return -1;
    }

    int mid = (first + last) / 2;

    if ( dataArray[mid] == target ){
        cout<<"item found at index "<<mid<<endl;
        return mid;
    } 

    if ( target < dataArray[mid] ){
        return binarySearch(dataArray, first, mid - 1, target);
    }     

    else{
       int newFirst = mid + 1; 
       return binarySearch(dataArray, first, mid + 1, target);
    } 
}