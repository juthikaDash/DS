//951. Flip Equivalent Binary
//https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24
/**
 * Definition for a binary tree node.
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) { return true;} //both null
        if((!root1 or !root2)or (root1->val != root2->val) ){ return false;}

        return ((flipEquiv(root1->left,root2->left) and flipEquiv(root1->right, root2->right)) or //no flip
                (flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left))   //flip   
                );
    }
};