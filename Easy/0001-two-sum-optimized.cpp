// Optimizes Apporach :::  unordered_map() :
/*
//////////////  Two Sum  : LeetCode : 0001  ///////////
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int sec = target - first;

            if (m.find(sec) != m.end()) {
                return {m[sec], i};
            }
            m[first] = i;

        }
        return {};
    }

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector <int> ans = twoSum(nums, target);

    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}