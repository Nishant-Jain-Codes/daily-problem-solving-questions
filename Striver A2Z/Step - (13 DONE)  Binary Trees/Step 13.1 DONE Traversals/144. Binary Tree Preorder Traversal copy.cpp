// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    //iterative
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        if(root==NULL)
            return ans;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top();
            stk.pop();
            ans.push_back(t->val);
            if(t->right)
                stk.push(t->right);
            if(t->left)
                stk.push(t->left);
        };
        return ans;
    }
    // //recursive
    void preOrder(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL)
            return ;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root,ans);
        return ans;
    }
};