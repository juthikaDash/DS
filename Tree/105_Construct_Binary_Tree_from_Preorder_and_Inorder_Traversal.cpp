//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include<iostream>
#include<unordered_map>
#include<vector>
 using namespace std;
/**
 * Definition for a binary tree node.
 * **/
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
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(preorder.size() == 0 or inorder.size() == 0){ return nullptr;}
       //make the map
       for(int i =0; i<inorder.size(); i++){
       inorderIndexMap[inorder[i]] =i; 
       }
       return arrayToTree(preorder,0,preorder.size()-1);
    }
    TreeNode* arrayToTree(vector<int>& preorder,int left, int right){
        if(left>right){ return nullptr;}
        int rootval = preorder[preorderIndex++];
        auto root = new TreeNode(rootval); 
        root->left = arrayToTree(preorder, left,inorderIndexMap[rootval]-1) ;
        root->right = arrayToTree(preorder, inorderIndexMap[rootval]+1,right) ;
        return root;
    }
};
