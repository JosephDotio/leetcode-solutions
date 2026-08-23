// LeetCode - 540 ::::::::::
// Single element in sorted array :::::::
/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) {
            return nums[0];
        }

        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (mid == 0 && nums[0] != nums[1]) return nums[mid];
            if (mid == n - 1 && nums[n - 1] != nums[n-2]) return nums[mid];

            if (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            } 
            
            if (mid % 2 == 0) {
                if (nums[mid-1] == nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if (nums[mid-1] == nums[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << "Single Element in Sorted Array : " << singleNonDuplicate(nums) <<endl;

    return 0;
}