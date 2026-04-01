// class LRUCache {
// public:
//     LRUCache(int capacity) {
        
//     }
    
//     int get(int key) {
        
//     }
    
//     void put(int key, int value) {
        
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */



#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            int ans = node->val;

            deleteNode(node);
            addNode(node);

            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            deleteNode(node);
            m.erase(key);
        }

        if (m.size() == cap) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};