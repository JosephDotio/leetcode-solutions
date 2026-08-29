// LeetCode : 204
// Sieve of Eratosthenes : [Count prime numbers in a range] ::::
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 1; // prime number 2

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }

int main() {
    int n;

    cout << "Enter n : ";
    cin >> n;

    int dig = countPrimes(n);
    cout << dig << endl;



    return 0;
}    