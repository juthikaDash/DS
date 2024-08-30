//https://leetcode.com/problems/house-robber/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0, rob2 = 0;
        //[ro1,rob2,n,n+1,n+2,n+3...]
        for(int n:nums){
            int temp = max(rob1+n, rob2);
            rob1 = rob2;
            rob2= temp;
        }
        return rob2;
    }
};
