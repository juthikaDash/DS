//https://leetcode.com/problems/product-of-array-except-self/description/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      std::vector<int> res(size(nums),1);

        int n = nums.size();
        if(n==0){ return res;}  

        res[0] = 1;
        for(int i=1;i<n;i++){
            res[i] = res[i-1] * nums[i-1];
            cout << res[i];
        }
        int prod =1;

        for (int j = n -1 ;j >= 0;j--)
        {
            res[j] = res[j] * prod;
            prod *= nums[j]; 
        }
        return res;  
    }
};
