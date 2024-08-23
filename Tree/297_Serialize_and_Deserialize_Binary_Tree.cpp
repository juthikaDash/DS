//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
/**
 * Definition for a binary tree node.
 * */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string res;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        auto node= q.front();
        q.pop();
        if(node == nullptr){
            res.append("#,");
        }
        else{
            res.append(to_string(node->val));
            res.append(",");
            q.push(node->left);
            q.push(node->right);
        }
       }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){ return nullptr;}

        queue<TreeNode*> q;
        string str;
        //converting the string into stream and read using delemiter
        stringstream data_stream(data);
        getline(data_stream,str,',');
        if(str == "#"){ return nullptr;};
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            auto temp_node = q.front();
            q.pop();

            //handle the lft child
            getline(data_stream,str,',');
            if(str == "#"){
                temp_node->left = nullptr;
            }
            else{
                TreeNode* left = new TreeNode(stoi(str));
                temp_node->left = left;
                q.push(left);
            }
        //handle the iii child
            getline(data_stream,str,',');
            if(str == "#"){
                temp_node->right = nullptr;
            }
            else{
                TreeNode* right = new TreeNode(stoi(str));
                temp_node->right = right;
                q.push(right);
            }}
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

