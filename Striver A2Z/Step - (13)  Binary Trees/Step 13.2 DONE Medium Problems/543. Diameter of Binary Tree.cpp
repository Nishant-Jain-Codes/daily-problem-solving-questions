// https://leetcode.com/problems/diameter-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int,int> helper(TreeNode * root){
        if(root==NULL)
            return {0,0};
        pair<int,int> leftAns = helper(root->left);
        pair<int,int> rightAns = helper(root->right);
        int height = 1 + max(leftAns.first,rightAns.first);
        int diameter = max(1+leftAns.first+rightAns.first,max(leftAns.second,rightAns.second));
        return {height,diameter};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second-1;        
        // -1 because they are starting from '0'
    }
};