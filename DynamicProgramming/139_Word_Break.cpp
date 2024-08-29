//https://leetcode.com/problems/word-break/description/
/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/
//o(n.m.n)
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(),false);
        //dp[0] = true;
        for(int i =0; i < s.length(); i++){
            for (auto word:wordDict ){
                if(i < word.length()-1){ continue;}
                if( i == word.length()-1 || dp[i-word.length()]){
                    if(s.substr(i-word.length()+1, word.length()) == word){
                        dp[i] = true;
                        break;
                    }


                }
            }
        }
        return dp[s.size()-1];
    }
};
