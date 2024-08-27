//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

#include<iostream>
#include<unordered_map>
#include<vector>
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
    unordered_map<int, int> mp;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    int postindex = size -1, inorderend = size-1, inorderstart = 0;
    for (int i = 0; i< size; i++){
        mp[inorder[i]] = i;
    }
    return solver(inorder,postorder, postindex, inorderstart,inorderend);
    }

   TreeNode* solver(vector<int>& inorder,vector<int>& postorder, int &postindex, int inorderstart,int inorderend){
    //base condition
    if(postindex <0 || inorderstart > inorderend){ return NULL;}

    int rootval = postorder[postindex];
    postindex--;
    auto root = new TreeNode(rootval);
    int pos = mp[rootval];

    root->right = solver(inorder,postorder, postindex,pos+1, inorderend);
    root->left = solver(inorder,postorder, postindex,inorderstart, pos-1);
    return root;
   }
};
