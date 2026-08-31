
// LeetCode - 704 : Binary Search 
/*
Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st) / 2;

        if (tar == nums[mid]) {
            return mid;
        } else if (tar >= nums[mid]) {
            return binarySearch(nums, tar, mid+1, end);
        } else {
            return binarySearch(nums, tar, st, mid-1);
        }
    }
    return -1;
}

int search(vector<int>& nums, int tar) {
        int st = 0, end = nums.size() - 1;
        return binarySearch(nums, tar, st, end);
    
}    

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int tar = 9;

    cout << "BS : " << search(nums, tar) << endl;

    return 0;
}