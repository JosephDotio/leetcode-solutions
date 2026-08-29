
// LeetCode : 9 - Palindrome Number::
/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/
#include <iostream>
#include <limits>
using namespace std;

int reverse(int n) {
    int revNum = 0;

    while (n != 0) {
        int dig = n % 10;

        if (revNum > INT_MAX/10 || revNum < INT_MIN) {
            return 0;
        }

        revNum = revNum * 10 + dig;
        n = n / 10;
    }
    return revNum;
}

bool isPalindrome(int n) {
    if (n < 0) return false;

    int revNum = reverse(n);

    return n == revNum;
}

int main() {
    int n = 121;

    if (isPalindrome(n)) {
        cout << "Palindrome!" << endl;
    } else {
        cout << "Non-Palindrome!" << endl;
    }

    return 0;
}