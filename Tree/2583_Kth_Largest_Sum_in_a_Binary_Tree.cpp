//https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22
#include<iostream>
#include<queue>

using namespace std;

/**
 * Definition for a binary tree node.
 **/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minheap;
        queue<TreeNode*> q;
        q.push(root);

        //bfs
        while(!q.empty()){
            long long sum = 0;
            int size = q.size();
            for(int i = 0; i< size; i++){
                TreeNode* curr = q.front();q.pop();
                sum += curr->val ;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            minheap.push(sum);
            if(minheap.size() > k){
                minheap.pop();
            }

        }
        if(minheap.size() <k){
            return -1;
        }

        return minheap.top();
    }
};
