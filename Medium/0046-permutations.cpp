
// /////////////    45    ////////////
// LeetCode : 46 - Permutation ::::::
/*
Given an array nums of distinct integers, return all 
the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
using namespace std;

void getPermutation(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        getPermutation(nums, idx+1, ans);

        swap(nums[i], nums[idx]);   // BackTracking

    }
}

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getPermutation(nums, 0, ans);
        return ans;
    }

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for (vector<int> val : ans) {
        cout << "[";

        for (int x : val) {
            cout << x << " ";
        }
 
        cout << "]";
    }
    cout << endl;
    


    return 0;
}