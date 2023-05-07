// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<bool,bool> helperFunc(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &LCA){
        if(root==NULL)
            return {false,false};
        pair<bool,bool> leftSol = helperFunc(root->left,p,q,LCA);
        pair<bool,bool> rightSol = helperFunc(root->right,p,q,LCA);
        pair<bool,bool> rootCheck = {leftSol.first||rightSol.first||root==p,leftSol.second||rightSol.second||root==q};
        if(rootCheck.first&&rootCheck .second&&LCA ==NULL)
            LCA = root;
        return rootCheck;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root )
            return NULL;
        TreeNode* LCA=NULL;
        pair<bool,bool> sol = helperFunc(root,p,q,LCA);
        if(sol.first && sol.second)
            return LCA;
        else 
            return NULL;
    }
};