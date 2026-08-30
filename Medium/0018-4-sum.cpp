
// LeetCode : 18. 4 Sum :::::::::::
/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;

            int p = j + 1;
            int q = n - 1;

            while (p < q) {
                long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                if (sum < target) {
                    p++;
                }
                else if (sum > target) {
                    q--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                    p++;
                    q--;

                    while (p < q && nums[p] == nums[p-1]) {
                        p++;
                    }

                    while (p < q && nums[q] == nums[q+1]) {
                        q--;
                    }
                }
            }
        }
    }

    return ans;
}
int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for (vector<int> fourplet : ans) {
        for (int val : fourplet) {
            cout << val << " ";
        }
        cout << endl;
    }


    return 0;
}