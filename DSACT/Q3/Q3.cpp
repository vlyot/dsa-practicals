#include <iostream>
using namespace std;
int count_digit(int number) {
    if (number == 0) return 0; // Base case
    return 1 + count_digit(number / 10); // Recursive step
}

bool isPalindromeHelper(int num, int divisor) {
    if (num == 0) return true; // Base case
    int leading = num / divisor;
    int trailing = num % 10;
    if (leading != trailing) return false;
    return isPalindromeHelper((num % divisor) / 10, divisor / 100);
}

bool isPalindrome(int num) {
    if (num < 0) return false; // Negative numbers are not palindromes
    int divisor = 1;
    while (num / divisor >= 10) divisor *= 10;
    return isPalindromeHelper(num, divisor);
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	if (isPalindrome(n))
		cout << "Yes, " << n << " is a palindrome\n";
	else
		cout << "No, " << n << " is not a palindrome\n";
	return 0;
}
