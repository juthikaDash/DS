//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
/**
 * Definition for a binary tree node.
 * */

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(true){
            while(curr != nullptr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();s.pop();
            //decrement the count
            if(--k == 0){ return curr->val;}
            curr = curr->right;
        }
    }
};
