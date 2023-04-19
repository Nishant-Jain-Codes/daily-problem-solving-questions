// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> answer;
    if(root==NULL)
        return answer;
    queue<TreeNode*> pending;
    pending.push(root);
    int leftToRight=true;
    while(!pending.empty()){
        int size = pending.size();
        vector<int> thisLevel(size);
        for(int i=0;i<size;i++){
            TreeNode* fr = pending.front();
            pending.pop();
            if(fr->left)
                pending.push(fr->left);
            if(fr->right)
                pending.push(fr->right);
            int index = leftToRight?i:size-1-i;
            thisLevel[index]=fr->val;
                
        }
        leftToRight=!leftToRight;
        answer.push_back(thisLevel);
    }
    return answer;
    }
};