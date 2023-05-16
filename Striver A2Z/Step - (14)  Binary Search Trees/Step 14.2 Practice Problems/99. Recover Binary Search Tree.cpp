// https://leetcode.com/problems/recover-binary-search-tree/description/

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
private:
TreeNode* first;
TreeNode* mid;
TreeNode* last;
TreeNode* prev;    
    void inOrder(TreeNode* root){
        if(!root)
            return ;
        inOrder(root->left);
        if(prev && root->val < prev->val){
            if(!first)
            {
                first=prev;
                mid = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inOrder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=mid=last=NULL;
        inOrder(root);
        if(first&&last)
            swap(first->val,last->val);
        else if (first && mid)
            swap(first->val,mid->val);
    }
};