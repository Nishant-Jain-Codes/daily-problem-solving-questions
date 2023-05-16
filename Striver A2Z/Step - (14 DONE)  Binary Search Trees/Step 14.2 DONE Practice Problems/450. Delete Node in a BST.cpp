// https://leetcode.com/problems/delete-node-in-a-bst/description/


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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val == key){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* del = root;
            del->right = NULL;
            del->left = NULL;
            delete del;
            if(left && right){
                TreeNode* temp=right;
                while(temp->left)
                    temp = temp->left;
                temp->left = left;
                root=right;
            }
            else if(left){
                root=left;
            }
            else{
                root = right;
            }
        }
        else if(root->val > key){
            root -> left = deleteNode(root->left,key);
        }
        else {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};