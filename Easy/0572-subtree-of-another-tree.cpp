// LeetCode : 572. Subtree Tree of Another Tree
/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
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

    // Check whether two trees are identical
    bool isIdentical(TreeNode* p, TreeNode* q) {

        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        bool isLeftSame = isIdentical(p->left, q->left);
        bool isRightSame = isIdentical(p->right, q->right);

        return isLeftSame && isRightSame && p->val == q->val;
    }

    // Check whether subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr || subRoot == nullptr) {
            return root == subRoot;
        }

        if (root->val == subRoot->val &&
            isIdentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {

    // Main Tree:
    //
    //          3
    //         / \
    //        4   5
    //       / \
    //      1   2

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Subtree:
    //
    //        4
    //       / \
    //      1   2

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;

    if (sol.isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root." << endl;
    } else {
        cout << "subRoot is not a subtree of root." << endl;
    }

    return 0;
}
