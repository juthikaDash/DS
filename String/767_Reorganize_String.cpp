#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {

public:

/*

    https://www.youtube.com/watch?v=2g_b1aYTHeg

    Here the approach is we need to track the frequency of the charcters in the string.
    Then we can pick highest freq and use it in our output string. 
    
    Then lets park the string that just used and then we can pick the next 2nd most highest freq chars.
    Then keep alternate.

    In the next loop we wil be adding the previously stored char once we reach from this.


*/
    string reorganizeString(string s) {
        unordered_map<char,int> charmap;
        for(char ss:s){
            charmap[ss] +=1;
        }
        //craete priority queue
        priority_queue<pair<int,char> > pq;
        for(auto data: charmap){
            pq.push( { data.second,data.first});
        }

        string result;
        pair<int,char> prev = {0,0};
        while(!pq.empty()){
            //pink mode req
            auto temp = pq.top();
            pq.pop();
            result +=temp.second;
            temp.first -=1;
            if(prev.first != 0){
                pq.push(prev);
                prev = {0,0}
            }

            if(temp.first != 0){
                prev = temp;
            }

            if(pq.empty() and prev.first != 0){
                return "";
            }
        }
        return result;
    }   
};