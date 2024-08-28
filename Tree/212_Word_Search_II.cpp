//https://leetcode.com/problems/word-search-ii/description/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Trie{
 public:
    Trie* children[26];
    bool endOfWord =  false;
    Trie():endOfWord(false){
        for(int i = 0; i< 26; i++){
            children[i] = nullptr;
        }
    }
    ~Trie(){
        for(int i = 0; i<26; i++){
            if(children[i] != nullptr){
                delete children[i];
            }
        }
    }
    void insert(string word){
        Trie* curr = this;
        for(int i =0; i<25; i++){
            auto index = word[i] - 'a';
            if(index >25 || index<0){ break;}
            if(curr->children[index] == nullptr){
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
        }
        curr->endOfWord = true;
    }
};
class Solution {
public:
    unordered_set<string> result;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0 ) { return {};}
        Trie trie;

        for(auto word: words){
            trie.insert(word);
        }

        for(int i = 0; i< board.size(); i++){
            for(int j = 0; j< board[0].size();j++){
                dfs(board,&trie,i, j, "");
            }
        }
        vector<string> v_result(result.begin(),result.end());
        return v_result;
    }
    void dfs(vector<vector<char>>& board, Trie* trie, int i, int j, string mystring){
        char ch = board[i][j];
        if(ch == '$'){ return ;}
        board[i][j] == '$';
        Trie* t = trie->children[ch - 'a'];
        if(t != nullptr){
            string ss = mystring + ch;
            if(t->endOfWord){ result.insert(ss);}
            if(i < board.size() -1){
                dfs(board, t , i+1, j, ss);
            }
            if(i > 0){ dfs(board, t, i-1, j,ss);}
            if(j<board[0].size()-1){ 
                dfs(board,t,i,j+1, ss);
                }
            if(j > 0){dfs(board,t,i, j-1,ss);}
        }
        board[i][j] = ch;
    }
};

