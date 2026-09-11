// LeetCode - 146. LRU Cache
/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
*/

// LeetCode - 146. LRU Cache

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

private:
    int cap;
    unordered_map<int, Node*> m;

    Node* head;
    Node* tail;

    // Remove a node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node just after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;

        // Dummy head and tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {

        // Key doesn't exist
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* node = m[key];

        // Move node to front because it is recently used
        removeNode(node);
        addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            Node* node = m[key];

            node->val = value;

            // Move to front
            removeNode(node);
            addNode(node);

            return;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // Add to map
        m[key] = newNode;

        // Add to front
        addNode(newNode);

        // If capacity exceeded
        if (m.size() > cap) {

            // Least recently used node is just before tail
            Node* lru = tail->prev;

            removeNode(lru);

            m.erase(lru->key);

            delete lru;
        }
    }
};

int main() {

    LRUCache* obj = new LRUCache(2);

    obj->put(1, 1);
    obj->put(2, 2);

    cout << obj->get(1) << endl;  // 1

    obj->put(3, 3);

    cout << obj->get(2) << endl;  // -1

    obj->put(4, 4);

    cout << obj->get(1) << endl;  // -1
    cout << obj->get(3) << endl;  // 3
    cout << obj->get(4) << endl;  // 4

    return 0;
}