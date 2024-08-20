//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<iostream>
#include<string>
using namespace std

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int max_len = 0;
        std::unordered_map<char, int> map;
        while(j<s.length()){
            //if already saw the char
            if(map.find(s[j]) != map.end()){
                i = max(i, map[s[j]]);
            }
            map[s[j]] = j+1;
            max_len = max(max_len, j-i+1);
            j+=1;
        }
        return max_len;
    }
};
