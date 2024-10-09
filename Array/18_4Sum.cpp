//https://leetcode.com/problems/4sum/description/
#include<iostream>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        kSum(nums, target, 4);
        return ans;
    }
    void kSum(vector<int>& nums, int target,int k){
        vector<int> temp;
        dfs(nums, 0, nums.size()-1, k, target, temp);

    }
    void dfs(vector<int>& nums, int l, int r, int k, long long target, vector<int>& path ){
        //two sum
        if(k == 2){
            while(l<r){
                if(nums[l]+nums[r] == target){
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    ans.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    while(l+1 <r && nums[l] == nums[l+1]) l++;
                    ++l;
                    --r;
                }
                else if( nums[l]+ nums[r] > target){
                    --r;
                }
                else{
                    ++l;
                }
            }
        }
        //else
        while(l<r){
            path.push_back(nums[l]);
            dfs(nums, l+1,r,k-1,target-nums[l], path);
            path.pop_back();
            while(l+1 <r and nums[l] == nums[l+1])
                ++l; //skips the duplicates
        }
    }
};
int main(){
    Solution s;
    vector<int> input = {1,0,-1,0,-2,2};
    s.fourSum( input,0);
    //cout << s.ans << endl;
    return 0;
}
