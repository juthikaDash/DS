//https://leetcode.com/problems/palindromic-substrings/description/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>

using namespace std;
class Solution {
public:
    int count_pali(string &s,int l,int r){
        int res = 0;
        while( l>=0 and r <s.length() and s[l] == s[r]){
            res++;
            --l;
            ++r;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i =0 ; i<s.length(); i++){
            //for odd
            int l = i, r =i;
            res += count_pali(s, l,r);

            //for even
            l = i, r = i+1;
            res += count_pali(s,l,r);
        }
        return res;
         
    }
};