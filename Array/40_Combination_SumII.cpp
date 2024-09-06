//https://leetcode.com/problems/combination-sum-ii/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
/*
This code is an algorithm to find all combinations from the given candidates 
list that sum up to target. First, the candidates list is sorted in non-decreasing 
order. An empty list res is initialized to store all valid combinations. 
The recursive function dfs takes parameters target (current total sum), 
start (starting index in candidates), and comb (current combination being built).
 As base cases, if target < 0, the function returns immediately, 
 and if target == 0, comb is added to res. 
 The dfs function iterates through the candidates list from start, skipping 
 duplicates and ensuring no reuse of values to avoid redundancy. 
 It also terminates search paths if the current candidate exceeds target. 
 The initial call dfs(target, 0, []) starts the exploration, and after all valid 
 combinations are found, res is returned.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        dfs(candidates,target,0,comb,res);
        return res; 
    }
    void dfs(vector<int>& candidates,int target,int start,vector<int>& comb,vector<vector<int>>& res){
        //target less than 0;
        if(target <0){
            return;
        }
        //target ==0
        if(target ==0){
            res.push_back(comb);
            return;
        }
        for(int i =start; i<candidates.size();i++){
            if((i>start) && (candidates[i] == candidates[i-1])){
                continue;
            }

            if(candidates[i] > target){
                break;
            }
            comb.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1, comb,res);
            comb.pop_back();
        }
    }

};
