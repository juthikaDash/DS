//https://leetcode.com/problems/alien-dictionary/submissions/1349934385/
/*
There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are 
sorted lexicographically
 by the rules of this new language.

If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".

Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        set<pair<char, char>> st;
        unordered_set<char> ch;
        vector<int> in(256);

        queue<char> q;
        string res;
        for (auto a : words) ch.insert(a.begin(), a.end());
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < mn; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    st.insert(make_pair(words[i][j], words[i + 1][j]));
                    break;
                }
            }
            if (j == mn && words[i].size() > words[i + 1].size()) return "";
        }
        for (auto a : st) ++in[a.second];
        for (auto a : ch) {
            if (in[a] == 0) {
                q.push(a);
                res += a;
            } 
        }
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : st) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";

        
    }
};