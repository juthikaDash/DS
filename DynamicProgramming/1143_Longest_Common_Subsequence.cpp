//https://leetcode.com/problems/longest-common-subsequence/description/
/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/
#include <cstring>
#include <iostream>

using namespace std;

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //find the length of 2 strings
        int n1 = text1.length();
        int n2 = text2.length();

        //bottom up , so create dp 2-d array
        int dp[n1+1][n2+1];
        //We need to inittalize first col and row to zero but lets just memset all to 0
        std::memset(dp,0,sizeof(dp));

        for(int i=1; i<=n1; i++){
            for (int j =1; j<=n2; j++){
                if(text1[i-1]== text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[j][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

int main(){
    Solution s;
    int res = s.longestCommonSubsequence("abcde","ace");
    cout<< " Longest Common Subsequence"<< res <<endl;
    return 0;
}