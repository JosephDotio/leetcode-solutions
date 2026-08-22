/*
 11. Container with most water :::::

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <iostream>
using namespace std;

int maxArea(vector<int> &height) {
    int n = height.size();
    int maxWater = 0;

    int left = 0, right = n - 1;

    while (left < right) {
        int width = right - left;
        int heightBar = min(height[right], height[left]);
        int area = heightBar * width;

        maxWater = max(maxWater, area);

        height[left] < height[right] ? left++ : right--;

        // if (height[left] < height[right]) {
        //     left++;
        // } else {
        //     right--;
        // }

    }
    return maxWater;
}

int main() {
    vector <int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Container with Most water : " << maxArea(height) << endl;

    return 0;
}
