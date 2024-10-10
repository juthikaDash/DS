//https://leetcode.com/problems/last-stone-weight/
#include<iostream>
#include<queue>

using namespace std;

class Solution{
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> pq;
            for(int s: stones){
                pq.push(s);
            }

            while(pq.size() >1){
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();

                int x = first - second;
                if(x >0){
                    pq.push(x);
                }
            }

            if(pq.size() > 0){
                return pq.top();
            }
            else{
                return 0;
            }
        }
};

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    Solution s;
    int output  = s.lastStoneWeight(stones);
    cout << "Last stone weight: "<<output<<endl;
    return 0;
}