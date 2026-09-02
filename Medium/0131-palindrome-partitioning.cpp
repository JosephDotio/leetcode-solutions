// LeetCode - 131. palindrome partitioning
/*
Given a string s, partition s such that every substring 
of the partition is a palindrome. Return all possible
palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalin(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());

    return s == s2;
}

void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans) {
    if (s.size() == 0) {
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i+1);

        if (isPalin(part)) {
            partitions.push_back(part);
            getAllParts(s.substr(i+1), partitions, ans);
            partitions.pop_back();  // Back Tracking
        }
    }
}

vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;

        getAllParts(s, partitions, ans);

        return ans;
    }

int main() {
    string s = "aab";
    vector<vector<string>> ans = partition(s);

    for (vector<string> x : ans) {
        cout << "[";

        for (int i = 0; i < x.size(); i++) {
            cout << x[i];

            if (i != x.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    


    return 0;
}