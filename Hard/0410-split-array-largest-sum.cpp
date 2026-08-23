// LeetCode = 410 ::::::::::
/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/

#include <iostream>
#include <vector>
using namespace std;

    bool isValid(vector<int>& nums, int k, long long maxAllowedSum) {
        int subArrays = 1;
        long long sum = 0;

        for (int num : nums) {
            if (num > maxAllowedSum) {
                return false;
            }

            if (sum + num <= maxAllowedSum) {
                sum += num;
            } else {
                subArrays++;
                sum = num;
            }

        }
        return subArrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int st = 0, end = sum;

        int ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

int main() {
    vector<int> nums = {7,2,5,10,8};
    int k = 2;

    cout << "Split Array Largest Sum : " << splitArray(nums, k) << endl;

    return 0;
}