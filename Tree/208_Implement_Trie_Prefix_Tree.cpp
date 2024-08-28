//https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include<iostream>
#include<string>
using namespace std;
class TriNode{
    public:
        TriNode* map[26] = {0};
        bool endOfWord = false;
        int refCount = 0;
};

class Trie {
public:TriNode* root;
    Trie() {
        root =  new TriNode();
    }
    
    void insert(string word) {
        if(word.length() == 0){ return;}
        TriNode* node = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(node->map[idx] == NULL){
                node->map[idx] = new TriNode();
                node->refCount +=1;
            }
            node = node->map[idx];
        }    
        node->endOfWord = true;
    }
    
    bool search(string word) {
        if(word.length() == 0){ return false;}

        TriNode* curr = root;
        for(auto ch : word){
            int index = ch - 'a';
            if(curr->map[index] == nullptr){ return false;}

            curr = curr->map[index];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        if(prefix.length() == 0){ return false;}
        TriNode* curr = root;
        for(auto ch: prefix){
            int index = ch - 'a';
            if(curr->map[index] == nullptr){ return false;}
            curr = curr->map[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

