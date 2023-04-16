// https://leetcode.com/problems/validate-binary-search-tree/description/

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
    // O(N) space and O(N) time 
    void inOrder_Traversal(TreeNode* root, vector<int> & inOrder){
        if(root==NULL)
            return ;
        inOrder_Traversal(root->left,inOrder);
        inOrder.push_back(root->val);
        inOrder_Traversal(root->right,inOrder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        inOrder_Traversal(root,inOrder);
        for(int i=0;i<inOrder.size()-1;i++){
            if(inOrder[i]>=inOrder[i+1])
                return false;
        }
        return true;
    }
};