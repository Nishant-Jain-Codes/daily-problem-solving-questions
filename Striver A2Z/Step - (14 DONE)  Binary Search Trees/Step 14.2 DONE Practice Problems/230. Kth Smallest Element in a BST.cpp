// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    void solutionN(TreeNode* root, int k ,int &curNo , int& ans){
        if(root==NULL){
            return ;
        }
        solutionN(root->left,k,curNo,ans);
        curNo++;
        ans = curNo==k ? root->val : ans;
        solutionN(root->right,k,curNo,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int curNo = 0;
        solutionN(root,k,curNo,ans);
        return ans;
    }

};