// 238. Product of array except self :::::::::::
/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int product = 1;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                product = product * nums[j];
            }
        }
        ans.push_back(product);
    }
    return ans;
        
    }

int main() {
    vector<int> nums = {1, 2, 3, 4};

    for (int productArray : productExceptSelf(nums)) {
        cout << productArray << " ";
    }
    cout << endl;
    

    return 0;
}