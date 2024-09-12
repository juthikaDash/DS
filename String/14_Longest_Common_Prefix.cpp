//https://leetcode.com/problems/longest-common-prefix/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0){return "";}
        if(strs.size() == 1){ return strs[0];}
        for(int i =0; i<strs[0].length();i++){
            for(string s : strs){
                if((s[i] != strs[0][i]) or (i == s.length())){
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0].substr(0, INT_MAX);
    }
};
