//https://leetcode.com/problems/roman-to-integer/description/
#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> romnint = {
            {'I', 1}, 
            {'V', 5},
            {'X', 10},
            {'L', 50}, 
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int sum = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(romnint[s[i+1]] <= romnint[s[i]]) 
                sum += romnint[s[i]]; 
            else  
                sum -= romnint[s[i]];  
        }
        return sum;
    }
};
