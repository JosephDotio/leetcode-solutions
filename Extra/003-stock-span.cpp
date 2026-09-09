// Question — Stock Span
/*
Given an array price[] where price[i] represents the stock price on the i-th day, calculate the stock span for each day.
The stock span for a day is the maximum number of consecutive days ending on that day for which the stock price was less than or equal to today's price.
Example
Input:  price = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]

Explanation
For 75 (day 6):
Prices: 60, 70, 60, 75
All consecutive prices going backward are less than or equal to 75.
Span = 4
For 85 (day 7):
100, 80, 60, 70, 60, 75, 85
↑
100 is greater than 85, so we stop.
Therefore:
Span = 6
Your Task
Write a C++ program to calculate the stock span for every day using a stack.
Expected output:
1 1 1 2 1 4 6
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // stock price
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // solution
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for (int i = 0; i < price.size(); i++) {
        while (s.size() > 0 && price[s.top()] <= price[i]) {
            s.pop();
        }

        if (s.size() == 0) {
            ans[i] = i+1;
        } else {
            ans[i] = i - s.top(); // i-pH
        }

        s.push(i);
    }

    // print answer val
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
