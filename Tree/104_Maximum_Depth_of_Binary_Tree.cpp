//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include<iostream>
#include<queue>
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
    /*
    - Recursive Methold
    - Base case of the unwind the system stack is when the curr == NULL
    - Hence if the node is NULL it will return the depth as 0
    - For each node depth  = 1 + max(depth of left sub-child, depth of the right sub-child)
    - when we move from the leave node to root,  each step we will calculate the depth send it to it's root
    */
    int maxDepth(TreeNode* root) {
        if(root == nullptr){ return 0;}
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
    /*
    - Iterative BFS
    - We can use a queue to push the elements
    - lets start with level 0 and push the nodes
    - each time we remove the node from the queue 
    - we will be adding its childern and increment the level
    - 
    */
       int maxDepth_iterative(TreeNode* root) {
            int level = 0;
            if(root == nullptr){ return level;}
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){
                int len = q.size();
                for(int i =0; i< len; i++){
                    auto node =  q.front();
                    q.pop();
                    if(node->left){ q.push(node->left);}
                    if(node->right){q.push(node->right);}
                }
                level +=1;
            }
            return level;

       }
};

