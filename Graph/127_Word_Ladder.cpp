//https://leetcode.com/problems/word-ladder/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        //checks if the endword is presend in the dict
        bool isPresent = false;
        for(auto word:wordList){
            if(endWord.compare(word) == 0){
                isPresent = true;
            }
            myset.insert(word);
        }

        if(isPresent == false){return 0;}
        //bfs
        queue<string> q;
        q.push(beginWord);
        int depth =0;
        while(!q.empty()){
            depth +=1;
            int lsize = q.size();
            while(lsize--){
                string curr = q.front();
                q.pop();
                //check for all possible 1 depth word
                for(int i = 0; i<curr.length();i++){
                    string temp = curr;
                    for(char c = 'a'; c<='z'; c++){
                        temp[i] = c;
                        if(curr.compare(temp) == 0)
                            continue; //skip the same word
                        if(temp.compare(endWord) == 0){
                            return depth+1;
                        }
                        if(myset.find(temp) != myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};