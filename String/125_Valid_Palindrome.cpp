//https://leetcode.com/problems/valid-palindrome/description/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int start =0, end = s.length() -1;

        while(start< end){
            while(start <end and !isalnum(s[start])){
                start++;
            }
            while(start <end and !isalnum(s[end])){
                end--;
            }

            if(tolower(s[start]) !=tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};