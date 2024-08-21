//https://leetcode.com/problems/longest-repeating-character-replacement/description/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
       int j = 0, res =0, max_freq = 0;
        int freq[26] = {0};


        for(int i = 0; i< s.length(); ++i){
            freq[s[i] - 'A'] +=1;
            max_freq =  max(max_freq,freq[s[i] - 'A'] );

            int win_size = i - j +1;
            if(win_size - max_freq > k ){
                ++j;
                freq[s[j] - 'A'] -=1;
            }
            res = max(res, i-j+1);
        }

        return res;
    }
};
