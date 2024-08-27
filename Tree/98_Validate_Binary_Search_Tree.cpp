//https://leetcode.com/problems/validate-binary-search-tree/description/
#include<iostream>
#include<unordered_map>
#include<vector>
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
 #define MIN INT_MIN
 #define MAX INT_MAX
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       return isBST(root, MIN, MAX) ;
    }
    bool isBST(TreeNode* root, long long min, long long max){
        if (root == nullptr){ return true;}

        if(root->val <= min || root->val >= max){ return false;}

        //check the left
        if(root->left != nullptr){
            if(!isBST(root->left, min, root->val)){
                return false;
            }
        }

        //check right tree
        if(root->right != nullptr){
            if(!isBST(root->right,root->val, max)){
                return false;
            }
        }

        return true;
    }
};
