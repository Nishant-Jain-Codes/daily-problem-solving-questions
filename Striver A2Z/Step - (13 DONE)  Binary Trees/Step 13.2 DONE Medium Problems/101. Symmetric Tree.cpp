// https://leetcode.com/problems/symmetric-tree/description/

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
    //recursive solution 
    bool checker(TreeNode* n1, TreeNode* n2){
        if(n1==NULL || n2 == NULL ) 
            return n1==n2;
        return (n1->val==n2->val) && checker(n1->left,n2->right) && checker(n1->right,n2->left); 
    }
    bool isSymmetric(TreeNode* root) {
        return checker(root,root);
    }
};