#include <iostream>
#include <string>
using namespace std;

int main(){
    int number;
    cout<< "Welcome to print integer program."<<'\n';
    cout<< "Please enter a 5-digit integer."<<endl<<flush;
    cin>>number;
    int digit1, digit2, digit3, digit4, digit5;
    digit1 = number/10000;
    digit2 = (number % 10000) / 1000;
    digit3 = (number % 1000) / 100;   
    digit4 = (number % 100) / 10;  
    digit5 = number % 10;            

    // Print each digit with three spaces between them
    cout << digit1 << "   " << digit2 << "   " << digit3 << "   " << digit4 << "   " << digit5 << endl;

    
    

    return 0;
}
