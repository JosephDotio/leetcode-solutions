
// //////////////   LeetCode : 78- Subsets   //////////////
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                   vector<vector<int>>& allSubsets) {

    if (i == nums.size()) {
        allSubsets.push_back(ans);
        return;
    }

    // Include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    ans.pop_back();

    // Exclude
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);

    return allSubsets;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> val = subsets(nums);

    for (vector<int> ans : val) {
        cout << "[ ";

        for (int x : ans) {
            cout << x << " ";
        }

        cout << "] ";
    }

    return 0;
}