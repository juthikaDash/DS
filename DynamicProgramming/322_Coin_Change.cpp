//https://leetcode.com/problems/coin-change/description/
/******************************************************
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
 */

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //base case
        if(amout == 0)
            return 0;
        if(coins.size() == 0)
            return -1;

        //Tabular
        //create dp array
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int a = 1; a<= amount; a++){
            for(int c: coins){
                if(a-c >= 0 ){
                    dp[a] = min(dp[a], dp[a-c]+1);
                }
            }
        }

        return (dp[amount] != amount+1? dp[amount]: -1);

    }
};