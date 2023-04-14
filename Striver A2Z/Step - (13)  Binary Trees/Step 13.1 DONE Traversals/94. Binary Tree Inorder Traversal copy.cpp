// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        vector<int> inorder;
        while(true){
            if(cur!=NULL){
                stk.push(cur);
                cur=cur->left;
            }else{
                if(stk.empty())
                    break ;
                cur = stk.top();
                stk.pop();
                inorder.push_back(cur->val);
                cur=cur->right;
            }
        }
        return inorder;
    }
    //recursive
    // void inOrder(TreeNode* root,vector<int>& ans)
    // {
    //     if(root==NULL)
    //         return ;
    //     inOrder(root->left,ans);
    //     ans.push_back(root->val);
    //     inOrder(root->right,ans);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     inOrder(root,ans);
    //     return ans;
    // }
};