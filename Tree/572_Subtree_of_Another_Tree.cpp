//https://leetcode.com/problems/subtree-of-another-tree/description/
#include<iostream>
#include<vector>
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
    bool isEqual(TreeNode* root, TreeNode* subRoot) {
        //if bot the trees are null return true
        if(root == nullptr and subRoot == nullptr){
            return true;
        }
        //if not null naf node->val are same
        if(root != nullptr && subRoot != nullptr && root->val == subRoot->val){
            auto left = isEqual(root->left, subRoot->left);
            auto right = isEqual(root->right, subRoot->right);
            return left && right;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       //if the subtree is null then return true
       if(subRoot == nullptr){ return true;} 
       if(root == nullptr){return false;}
       if(isEqual(root, subRoot)){
        return true;
       }
       return (isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot));
    }
};
