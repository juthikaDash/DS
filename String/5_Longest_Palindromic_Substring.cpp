//https://leetcode.com/problems/longest-palindromic-substring/description/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>

class Solution {
public:
    int max_length = INT_MAX;
    string res;
    void count_pali(string &s,int l,int r){
        while( l>=0 and r <s.length() and s[l] == s[r]){
            int curr_len = r -l + 1;
            if(curr_len > max_length){
                res = s.substr(l, curr_len);
                max_length = curr_len;
            }
            --l;
            ++r;
        }
    }
    string longestPalindrome(string s) {
        for(int i =0 ; i<s.length(); i++){
            //for odd
            int l = i, r =i;
            count_pali(s, l,r);

            //for even
            l = i, r = i+1;
            count_pali(s,l,r);
        }
        return res;
         
    }
};
