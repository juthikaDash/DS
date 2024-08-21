//https://leetcode.com/problems/valid-anagram/description/

#include<iostream>
#include<string>
using namespace std

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        int arr[26] = {0};
        for(int i = 0; i<s.length(); i++){
            arr[s[i] - 'a'] +=1;
            arr[t[i] - 'a'] -=1;
        }
        for(auto num:arr){
            if(num != 0){
                return false;
            }
        }
        return true;
    }
};
