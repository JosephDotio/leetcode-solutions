// //////////////////////  LeetCode : 88 - Merge Sorted Array  ///////////////////////
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: A = [1,2,3,0,0,0], m = 3, B = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int m, vector<int> &B, int n) {
    int idx = m+n-1, i = m-1, j = n-1;

    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[idx] = A[i];
            idx--, i--;
        } else {
            A[idx] = B[j];
            idx--, j--;
        }
    }

    while (j >= 0) {
        A[idx--] = B[j--];
    }
}

int main() {
    vector<int> A = {1,2,3,0,0,0}, B = {2,5,6};
    int m = 3, n = 3;

    merge(A, m, B, n);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;


    return 0;
}