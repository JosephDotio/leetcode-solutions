/*
Pow(x,n) :
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:
*/

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    if (x == 1) return 1.0;
    if (x == -1 && n%2 == 0) return 1.0;
    if (x == -1 && n%2 != 0) return -1.0;

        long binForm = n;
        if (n < 0) {
            x = 1/x;
             binForm = -binForm;
        }

        double ans = 1;

        while (binForm > 0) {
            if (binForm % 2 == 1) {
                ans = ans * x;
            }
            x = x * x;
            binForm = binForm / 2;
        }
        return ans;

    }

int main() {
    double x = 2.00000;
    int n = 10;

    cout << myPow(x, n) <<endl;

    return 0;
}