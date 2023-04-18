// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int HelperFunc(TreeNode* root , int & curMax){
        if(root==NULL)
            return 0 ;
        int leftAns = max(0,HelperFunc(root->left,curMax));
        int rightAns = max(0,HelperFunc(root->right,curMax));
        curMax = max(curMax , leftAns + rightAns + root->val);
        return root->val + max(leftAns,rightAns);
    }
    int maxPathSum(TreeNode* root) {
        int curMax = INT_MIN;
        int helperAns = HelperFunc(root,curMax);
        return curMax;
    }
};