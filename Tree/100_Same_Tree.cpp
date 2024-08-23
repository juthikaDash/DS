//https://leetcode.com/problems/same-tree/description/
/**
 * Definition for a binary tree node.
 * 
 * */
#include<iostream>
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
    // using DFS using recurrsion 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q== nullptr){
            return false;
        }

        if(p->val != q->val){ return false;}
        auto left = isSameTree(p->left, q->left);
        auto right = isSameTree(p->right, q->right);

        return (left && right);

    }
};
