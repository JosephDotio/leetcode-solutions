// LeetCode : 142. Linked List cycle II -->
/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCylce = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCylce = true;
                break;
            }
        }

        if (!isCylce) {
            return NULL;
        }

        slow = head;  // re-initialize
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* head2 = new ListNode(2);
    ListNode* head3 = new ListNode(0);
    ListNode* head4 = new ListNode(-4);

    // connecting
    head->next = head2;
    head2->next = head3;
    head3->next = head4;

    // cycling
    head4->next = head2;

    Solution obj;

    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle start at node : " << cycleStart->val << endl;
    } else {
        cout << "No Cycle" << endl;
    }

    return 0;
}