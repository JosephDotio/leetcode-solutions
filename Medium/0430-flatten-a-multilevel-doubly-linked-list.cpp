// LeetCode - 430. Flatten a Multilevel Doubly Linked List
/*
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child 
pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These 
child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example 
below.
Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened 
list.
Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:
*/

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {

                // Flatten the child node
                Node* next = curr->next;

                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // Find tail
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // attach tail with next ptr
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr =  curr->next;
        }
        return head;
    }
};

int main() {

    // Level 1
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();
    Node* node6 = new Node();

    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;
    node6->val = 6;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;


    // Level 2
    Node* node7 = new Node();
    Node* node8 = new Node();
    Node* node9 = new Node();
    Node* node10 = new Node();

    node7->val = 7;
    node8->val = 8;
    node9->val = 9;
    node10->val = 10;

    node7->next = node8;
    node8->prev = node7;

    node8->next = node9;
    node9->prev = node8;

    node9->next = node10;
    node10->prev = node9;


    // Level 3
    Node* node11 = new Node();
    Node* node12 = new Node();

    node11->val = 11;
    node12->val = 12;

    node11->next = node12;
    node12->prev = node11;


    // Connect child lists
    node3->child = node7;
    node8->child = node11;


    // Flatten
    Solution obj;
    Node* result = obj.flatten(node1);


    // Print flattened list
    Node* temp = result;

    while (temp != NULL) {
        cout << temp->val << " ⇄ ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    return 0;
}