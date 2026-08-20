// Example 1:
/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include <iostream>
using namespace std;

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    // int n = nums.size();
    int n = 9;

    int curSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        curSum = curSum + nums[i];
        maxSum = max(curSum, maxSum);

        if (curSum < 0) {
            curSum = 0;
        }
    }

    cout << "Maximum Subarray = " << maxSum <<endl;

    return 0;
}