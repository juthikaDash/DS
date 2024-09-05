//https://leetcode.com/problems/lru-cache/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
#include<iostream>
#include<unordered_map>
using namespace std;
class LRUCache {
    private:
    struct dNode{
        int key;
        int value;
        dNode* next;
        dNode* prev;
        dNode(int key, int value){
            this->key = key;
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
        //dNode():dNode(0,0){}
    };
    int capacity = 0;
    int item = 0;
    std::unordered_map<int, dNode*> hash;
    std::unordered_map<int, dNode*>::iterator it;

    //pointer to first node in the dqueue
    dNode* head = nullptr;
    //pointer to the last node
    dNode* tail = nullptr;


public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */