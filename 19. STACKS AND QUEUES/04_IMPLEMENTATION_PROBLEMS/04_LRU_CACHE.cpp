/*
#LRU CACHE

LINK:- https://leetcode.com/problems/lru-cache/description/
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLTION :- GET AND PUT OPERATION TAKING O(N) TIME
class LRUCache1 {
public:
    vector<pair<int, int>> cache;
    int n;
    LRUCache1(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i<cache.size(); i++){
            if(cache[i].first == key){
                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return val;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i<cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }

        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }else{
            cache.push_back({key, value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 //OPTIMAL SOLUTION, GET AND PUT TAKING O(1)
class LRUCache2 {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int key_, int val_){
                key = key_;
                val = val_;
                prev = nullptr;
                next = nullptr;
            }
    };

    void addnode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* newNode){
        Node* delPrev = newNode->prev;
        Node* delNext = newNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache2(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* resNode = mpp[key];
            int res = resNode->val;
            mpp.erase(resNode -> key);
            deleteNode(resNode);
            addnode(resNode);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* existNode = mpp[key];
            mpp.erase(existNode->key);
            deleteNode(existNode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addnode(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    
    return 0;
}