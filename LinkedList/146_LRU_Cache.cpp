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
        dNode():dNode(0,0){}
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
       this->capacity = capacity;
       head = new dNode();
       tail = new dNode();

       head->next = tail;
       tail->prev = head; 
    }
    
    int get(int key) {
        if((it = hash.find(key)) != hash.end()){
            auto node = hash[key];
            remove(node);
            add(node);
            return node->value;
        }
        return -1;
    }
    void remove(dNode* node){
    
        if(node ==NULL){ return;}
        node->next->prev = node->prev;
        node->prev->next = node->next;


    }
    void add(dNode* node){
        if(node == nullptr){
            return;
        }
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
   void update_data(dNode* node, int value) {
        if(node == NULL){ return;}
        node->value = value;
        remove(node);
        add(node);
   }
   dNode* remove_last_used(){
    dNode* node = tail->prev;
    node->prev->next = tail;
    tail->prev = node->prev;
    --item;
    return node;
   }
    void put(int key, int value) {
        //found in the hash table
       if((it = hash.find(key)) != hash.end()){
            //wite a fun to update
            update_data(it->second, value);
            return;
       } 
       //capacity reached so make space
       if(item >= capacity){
        auto node = remove_last_used();
        hash.erase(node->key);
       }

        //add new item
        dNode* node = new dNode(key, value);
        add(node);
        hash[key] = node;
        item++;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */