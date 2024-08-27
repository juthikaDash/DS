//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class WordDictionary {
    vector<WordDictionary*> children;
    bool endOfWord;
public:
    WordDictionary() {
    children = vector<WordDictionary*>(26,nullptr);
    endOfWord = false;

    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(auto ch:word){
            int index = ch - 'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new WordDictionary;
            }
            curr = curr->children[index];
        }
        curr->endOfWord = true;
        
    }
    
    bool search(string word) {
        auto curr = this;
        for(int i = 0; i< word.length();i++){
            auto c  = word[i];
            if(c == '.'){
                for(auto ch: curr->children){
                    if(ch and ch->search(word.substr(i+1))){return true;}
                }
                return false;
            }

            int index = c - 'a';
            if(curr->children[index] == nullptr){ return false;}
            curr = curr->children[index];
            }
            return curr && curr->endOfWord;

        }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */