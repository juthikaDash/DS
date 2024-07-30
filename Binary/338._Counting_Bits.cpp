//https://leetcode.com/problems/counting-bits/description/
/**********************************************************
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 **********************************************************/

#include<iostream>
#include <stdio.h>
#include<vector>


using namespace std;
class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> dp(n+1,0);
            int offset = 1;
            //first solution
            /*for(int i =1; i<=n;i++){
                if(offset*2 == i){
                    offset = i;
                }
                dp[i] = 1+ dp[i - offset];
            }
            */
            //2nd solution
            for(int i=1; i<=n;i++){
                dp[i] = dp[i/2] + i%2;
            }
            return dp;
        }
};
int main()
    {
        Solution s ;
        int n;
        cout << "Please enter an integer value: ";
        cin >> n;
        vector<int> res  = s.countBits(n );
       for (auto i:res)
            cout<< i<<" ";
        cout<<endl;
        return 0;
    }