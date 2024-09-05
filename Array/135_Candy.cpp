//https://leetcode.com/problems/candy/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        //checking the left neighbour
        for(int i =1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }

        //checking with the right neighbour
        for(int i =n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i], candy[i+1]+1);
            }
        }

        int totalCandies = 0;
        for(int c: candy){
            totalCandies += c;
        }
        return totalCandies;
    }
};