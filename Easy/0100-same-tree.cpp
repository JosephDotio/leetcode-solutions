// LeetCode - 100. Same Tree
/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If either node is NULL
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        // Check left and right subtrees
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        // Check current node and both subtrees
        return isLeftSame && isRightSame && p->val == q->val;
    }
};

int main() {

    // Tree 1:
    //       1
    //      / \
    //     2   3

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2:
    //       1
    //      / \
    //     2   3

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;

    if (sol.isSameTree(p, q)) {
        cout << "Both trees are same." << endl;
    } else {
        cout << "Both trees are not same." << endl;
    }

    return 0;
}
