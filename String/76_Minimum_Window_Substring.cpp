//https://leetcode.com/problems/minimum-window-substring/description/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT;
        unordered_map<char, int> window;

        //create the mapT
        for(auto c:t){
            mapT[c] +=1;
        }
        //Calculate the need and have
        int need = 0, have = 0;
        need = mapT.size();
        //define left and right of window
        int l = 0,r =0;
        int res[] = {INT_MAX,0,0};

        while(r< s.length()){
            auto ch = s[r];
            window[ch] +=1;

            if(mapT.find(ch) != mapT.end() and window[ch] == mapT[ch]){
                have +=1;
            }

            while(need == have){
                if(r-l+1 < res[0]){
                    res[0] = r-l+1;
                    res[1] = l;
                    res[2] = r;
                }

                window[s[l]] -=1;
                if(mapT.find(s[l]) != mapT.end() and window[s[l]] < mapT[s[l]]){
                    have -=1;
                }
                l +=1;
            }
            r +=1;
        }
        // window size = res[0];
        // left = res[1];
        // right = res[2];
        return (res[0] == INT_MAX) ? "" : s.substr(res[1], res[0]);
    }
};

