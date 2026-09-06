// LeetCode : 138. Copy List with Random Pointer :
/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value
of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the 
pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;

        }

        oldTemp = head; newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;

    }
};

int main() {
    // Create nodes
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    // Connect next pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Connect random pointers
    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    // Copy the list
    Solution obj;
    Node* copiedHead = obj.copyRandomList(node1);

    // Print copied list
    Node* temp = copiedHead;

    while (temp != nullptr) {
        cout << "Value: " << temp->val;

        if (temp->random != nullptr) {
            cout << ", Random: " << temp->random->val;
        } else {
            cout << ", Random: NULL";
        }

        cout << endl;
        temp = temp->next;
    }

    return 0;
}

    