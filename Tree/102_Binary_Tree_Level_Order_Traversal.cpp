//https://leetcode.com/problems/binary-tree-level-order-traversal/
/**
 * Definition for a binary tree node.
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
       vector<vector<int> > res;
       queue<TreeNode*> q;
       if(root == nullptr){ return res;}

       q.push(root);
       while(!q.empty()){
        vector<int> inner_res;
        int len = q.size();
        for(int i =0 ; i< len; i++){
            auto node =  q.front();
            q.pop();
            inner_res.push_back(node->val);
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        res.push_back(inner_res);
       }
       return res;
   }
};
