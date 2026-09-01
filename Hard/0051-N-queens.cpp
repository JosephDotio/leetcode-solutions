// LeetCode : 51.  N-Queens :::::::
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n){

    // vertical
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Left Diagonal
    for (int i=row, j=col; i>=0 && j>=0; i--,j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Right diagonal
    for (int i=row, j=col; i>=0 && j<n; i--,j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, row+1, n, ans);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }

int main() {
    vector<vector<string>> ans =  solveNQueens(4);

    for (vector<string> x : ans) {
        cout << "[";

        for (string y : x) {
            cout << y;
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}