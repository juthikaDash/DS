//https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150
//Time complexity: O(n)
//Space complexity: O(1)
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() -1;

        while(end >=0. and s[end] == ' '){
            end--;
        }

        int start = end;

        while(start >= 0 and s[start] != ' '){
            start--;
        }

        return end - start;
    }
};