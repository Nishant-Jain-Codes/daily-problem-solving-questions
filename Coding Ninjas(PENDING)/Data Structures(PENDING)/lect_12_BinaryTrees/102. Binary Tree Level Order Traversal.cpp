// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==NULL)
            return answer;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int size = q.size();
            vector<int> thisLevel;
            for(int i=0;i<size;i++){
                TreeNode* fr = q.front();
                q.pop();
                thisLevel.push_back(fr->val);
                if(fr->left)
                    q.push(fr->left);
                if(fr->right)
                    q.push(fr->right);
            }
            answer.push_back(thisLevel);

        }
        return answer;
    }
};