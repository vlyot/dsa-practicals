//print the numbers in an array in the backward manner
//param array – the array in concern
//param n – number of elements in the array
#include <iostream>
using namespace std;

void printBackward(int array[], int n){
    if (n<0){
        return;
    }
    else{
        cout<<n<<" : "<<array[n]<<endl;
        printBackward(array, n-1);
    }
};

int main(){
    int  arr[] = {10 ,20 ,30,40,50};
    printBackward(arr, 2);
    return 0;
}