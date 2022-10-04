/*

https://leetcode.com/problems/binary-tree-postorder-traversal/

*/

// solution 


void postOrder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return ;
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root,ans);
        return ans;
    }
