//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
/**
 * Definition for a binary tree node.
 **/
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
    int max_sum = INT_MIN;
    int dfs(TreeNode* root){
        if(root ==  nullptr){ return 0;}
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        //if we choose any -ve value, we can choose not to use thta
        int left_max = max(left,0);
        int right_max = max(right,0);
        max_sum = max(max_sum, (left+right)+root->val);
        //I can return what is the max sum that can see  using current node

        return (max(left_max,right_max)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};

