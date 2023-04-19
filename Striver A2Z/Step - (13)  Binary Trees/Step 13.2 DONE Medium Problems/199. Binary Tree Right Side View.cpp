// https://leetcode.com/problems/binary-tree-right-side-view/description/


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
    //using O(H) space and O(N) time 
    void helperFunc(TreeNode* root, map<int,int> & m , int curLevel){
        if(root==NULL)
            return ;
        
        m[curLevel] = root->val;
        helperFunc(root->left,m,curLevel+1);
        helperFunc(root->right,m,curLevel+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        map<int,int> m;
        int curLevel = 0;
        helperFunc(root,m,curLevel);
        for(auto &x : m){
            answer.push_back(x.second);
        }
        return answer;
    }
};