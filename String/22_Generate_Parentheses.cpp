//https://leetcode.com/problems/generate-parentheses/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
/*
    https://www.youtube.com/watch?v=s9fokUqJ76A
    
    There are three condition to certify
    - if number of open and close braces are same and matched given number then
      we can add the local res to the vector and return
    
    - add open braces only when open_count < number
    - add close braces only when close_count < open_count

*/
#include<iostream>
#include<vector>
using namespace std;  
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        create_parathesis(res, "",0,0,n);
        return res;
    }
    void create_parathesis(vector<string>& res,string lres,int open_count, int close_count, int max )
    {
        //base consition 
        if(open_count == max and close_count == max){
            res.push_back(lres);
        }

        //can add open braces only when no of open braces is less than max
        if(open_count <= max){
            create_parathesis(res,lres+"(",open_count+1,close_count,max);
        }

        //can add closing  braces whenb less than closing braces
        if(close_count < open_count){
            create_parathesis(res,lres+")",open_count,close_count+1,max);
        }
    }
};