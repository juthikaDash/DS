//https://leetcode.com/problems/top-k-frequent-elements/description/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
//Here two tings we need to track
//1. Frequency of each entry
//2. need to return k most frequesnt elemnets
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int> > topk;
        for(auto n:nums){
            freq[n]++;
        }
        for(auto it = freq.begin();it != freq.end();it++){
            topk.push( { it->second, it->first});
        }

        for(int i = 0; i<k;i++){
            res.push_back(topk.top().second);
            topk.pop();
        }

        return res;

    }
};