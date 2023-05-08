// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      if(preorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int leftStart = 1;
        int leftEnd = 1;
        
        while(leftEnd < preorder.size() && preorder[leftEnd] < preorder[0])
            leftEnd++;
        
        vector<int> leftPart(preorder.begin() + leftStart, preorder.begin() + leftEnd);
        vector<int> rightPart(preorder.begin() + leftEnd, preorder.end());

        root->left = bstFromPreorder(leftPart);
        root->right = bstFromPreorder(rightPart);
        
        return root;
    }
};