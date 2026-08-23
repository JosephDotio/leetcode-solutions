// Peak index in mountain array ::
/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

int main() {
    vector<int> arr = {0,2,5,10,1,0};

    cout << "Peak Index in Mountain Array : " << peakIndexInMountainArray(arr) << endl;

    return 0;
}