//https://leetcode.com/problems/gas-station/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(cost.size(),0);
        for(int i =0;i<gas.size(); i++){
            diff[i]= gas[i] - cost[i];
        }

        int res = 0;
        for(int i =0; i< cost.size();i++){
            res += diff[i];
        }

        if(res < 0){
            return -1;
        }
        res = 0;
        int idx= 0;
        for(int i = 0; i< cost.size();i++){
            res +=diff[i];
            if(res<0){
                idx =i+1;
                res = 0;
            }
        }
        return idx;
    }
};