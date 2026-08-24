// LeetCode == 75 : Color Sort
/*
You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Explanation:
The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.
*/


// Optimal ::: ---DNF alogo---  T.C = O(n)
#include <iostream>
#include <vector>
using namespace std;

void colorSort(vector<int> &nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++, mid++;

        } else if (nums[mid] == 1) {
            mid++;

        } else {
            swap(nums[high], nums[mid]);
            high--;

        }
    }
}

void printArray(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

    colorSort(arr);
    printArray(arr);

    return 0;
}