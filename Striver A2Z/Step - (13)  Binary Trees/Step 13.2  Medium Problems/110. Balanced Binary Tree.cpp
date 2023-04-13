// https://leetcode.com/problems/balanced-binary-tree/description/

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
    pair<int,bool> helperFunc(TreeNode * root){
        if(root==NULL)
            return {0,true};
        else
        {
            pair<int,bool> left_check = helperFunc(root->left);
            pair<int,bool> right_check = helperFunc(root->right);
            return {1+max(left_check.first,right_check.first),left_check.second && right_check.second && (abs(left_check.first-right_check.first)<=1)};
        }
    }
    bool isBalanced(TreeNode* root) {
        return helperFunc(root).second;        
    }
};