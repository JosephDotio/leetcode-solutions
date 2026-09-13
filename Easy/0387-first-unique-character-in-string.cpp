// LeetCode - 387. First Unique Character in a string
/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.
*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;

        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }

            m[s[i]]++;

            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};

int main() {
     Solution obj;
      string s = "level";
       int ans = obj.firstUniqChar(s);
        cout << "First unique character index: " << ans << endl;

    return 0;
}