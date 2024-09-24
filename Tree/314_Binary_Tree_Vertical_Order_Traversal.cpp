#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



class Solution {

using myMap = std::unordered_map <int, std::vector<std::pair<int, int>>>;

    public:
        vector<vector<int> > verticalOrder(TreeNode* root) {
           vector<vector<int> > result;

           if(!root){ return result;}

            queue<pair<TreeNode*, int> > q;
            q.push({root, 0});

            map<int, vector<int>> verticalLevels;

            while(!q.empty()){
                int n = q.size();

                for(int i = 0; i<n; i++){
                    auto node = q.front();
                    q.pop();
                    TreeNode* curr = node.first;
                    int level = node.second;
                    verticalLevels[level].push_back(curr->val);

                    if(curr->left){
                        q.push({curr->left,level-1});
                    }
                    if(curr->right){
                        q.push({curr->right,level+1});
                    }
                }
            }

            //generate the result
            for(auto entry : verticalLevels){
                result.push_back(entry.second);
            }

            return result; 

        }
};