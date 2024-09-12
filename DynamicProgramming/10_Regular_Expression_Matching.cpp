//https://leetcode.com/problems/regular-expression-matching/description/
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //length of the string and pattern
        auto slen = s.length();
        auto plen = p.length();
        bool match[slen+1][plen+1];
        memset(match,0, sizeof(match));
        match[0][0] = true;
        //special case a*,a*b*, a*b*c*
        for(int i=1;i<=p.length();i++){
            if(p[i-1] == '*'){
                if(i-2 >=0){
                    match[0][i] = match[0][i-2];
                }
            }
        }
        for(int i =1; i<=s.length();i++){
            for(int j = 1; j<=p.length();j++){
                //case 1 '.'
                if(p[j-1] == s[i-1] || p[j-1] == '.'){
                    match[i][j] = match[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    match[i][j]= match [i][j-2];
                    if(p[j-2] == s[i-1] || p[j-2] == '.')
                    {
                        match[i][j] = (match[i][j] || match[i-1][j]);
                    }
                }
                else{
                    match[i][j] = false;
                }
            }
        }
        return match[slen][plen];
    }
};
