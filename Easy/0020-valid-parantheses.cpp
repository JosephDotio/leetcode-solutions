// LeetCode : 20. Valid Parentheses
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.size() == 0) {
                    return false;
                }

                if ((st.top() == '(' && s[i] == ')') ||
                        (st.top() == '{' && s[i] == '}') ||
                            (st.top() == '[' && s[i] == ']')) {
                                st.pop();
                } else {
                    return false;
                } 
            }
        }
        return st.size() == 0;
    }
};

int main() {
    string s = "({[]}[])";

    Solution obj;
    bool result = obj.isValid(s);

    cout << boolalpha << result << endl;

    return 0;
}