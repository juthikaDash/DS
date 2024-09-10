//https://leetcode.com/problems/perfect-squares/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    int numSquares(int n) 
    {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int j = 1;j<=n;j++)
        {
            int mini = INT_MAX;
            for(int i = 1;i<=sqrt(j);i++)
            {
                int sq = i*i;
                int curr = 1 + dp[j - sq];
                mini = min(mini,curr);
            }
            dp[j] = mini;
            cout<< mini<<endl;
        }
        return dp[n];
    }
};
