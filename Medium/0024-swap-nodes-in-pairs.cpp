// LeetCode - 24.  Swap Nodes in Pairs
/*
Given a linked list, swap every two adjacent nodes and return its head.
 You must solve the problem without modifying the values in the list's nodes
  (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Explanation:
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = nullptr;

        while (first != nullptr && sec != nullptr) {
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;

            if (prev != nullptr) {
                prev->next = sec;
            } else {
                head = sec;
            }

            prev = first;
            first = third;
            if (third != nullptr) {
                sec = third->next;
            } else {
                sec = nullptr;
            }
        }
        return head;
    }
};

int main() {

    // Create linked list:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Swap nodes in pairs
    Solution obj;
    ListNode* result = obj.swapPairs(head);

    // Print result
    while (result != nullptr) {
        cout << result->val << " -> ";
        result = result->next;
    }

    cout << "NULL" << endl;

    return 0;
}