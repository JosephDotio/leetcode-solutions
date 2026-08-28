// LeetCode == 125 : Valid Palindrome
/*
A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include <iostream>
#include <cctype>
using namespace std;

bool isAlphaNumeric(char ch) {
    if ((ch >= '0' && ch <= '9') ||
        (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int n = s.size();
    int st = 0, end = n - 1;

    while (st < end) {

        if (!isAlphaNumeric(s[st])) {
            st++;
            continue;
        }

        if (!isAlphaNumeric(s[end])) {
            end--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        st++;
        end--;
    }

    return true;
}

int main() {
    string ch = "A man, a plan, a canal: Panama";

    if (isPalindrome(ch)) {
        cout << "It's a palindrome!" << endl;
    } else {
        cout << "It's not a palindrome!" << endl;
    }

    return 0;
}