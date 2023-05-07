// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


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
    TreeNode* flaterFunc(TreeNode* root){
        if(!root)
            return root;
        TreeNode * head = root;
        TreeNode *leftSol = flaterFunc(root->left);
        TreeNode *rightSol = flaterFunc(root->right);
        root->right=leftSol;
        root->left=NULL;
        TreeNode* temp = head;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=rightSol;
       
        return head;
    }
    void flatten(TreeNode* root) {
        TreeNode* sol =  flaterFunc(root);
    }
};