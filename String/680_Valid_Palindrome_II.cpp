//https://leetcode.com/problems/valid-palindrome-ii/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool check(string s, int l , int h){
        while(l<=h){
            if(s[l] !=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int  l = 0, h = s.size()-1;

        while(l<=h){
            if(s[l] == s[h]){
                l++;
                h--;
            }
            else{
                return (check(s,l+1,h) || check(s,l,h-1));
            }
        }
        return true;
    }
};