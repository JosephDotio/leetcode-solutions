/*
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <iostream>
#include <vector>
using namespace std;

int majorityElem(vector<int> nums) {
    int n = nums.size();
    int ans = 0, freq = 0;

    for (int i = 0; i < n; i++) {
        if (freq == 0) {
            ans = nums[i];
            freq = 1;
        } else if (ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
}

int main() {
    vector <int> nums = {2,2,1,1,1,2,2};

    int ans = majorityElem(nums);

    cout << "Majority elem = " << ans << endl;
 
    return 0;
}