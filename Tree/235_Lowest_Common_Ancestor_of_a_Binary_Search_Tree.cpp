//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    //Recurrsive option
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }

        int pval = p->val;
        int qval = q->val;
        int rootval = root->val;

        if(rootval > max(pval,qval)){
           return lowestCommonAncestor (root->left,p,q);
        }

        if(rootval < min(pval,qval)){
            return lowestCommonAncestor(root->right, p,q);
        }

        return root;
    }
        //Iterative option
   TreeNode* lowestCommonAncestor_iterative(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == nullptr){
            return nullptr;
        }

        int pval = p->val;
        int qval = q->val;
        int rootval = root->val;
        auto curr = root;
        int currval;

        while(curr != nullptr){
            currval = curr->val;
            if(pval > currval and qval > currval){
               curr = curr->right;
            }
            else if(pval < currval and qval < currval){
                curr = curr->left;
            }
            else{
                return curr;
            }
        }
        return nullptr;
    }
};
