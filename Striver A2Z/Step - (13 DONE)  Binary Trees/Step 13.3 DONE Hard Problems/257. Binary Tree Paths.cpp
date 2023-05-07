// https://leetcode.com/problems/binary-tree-paths/description/

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
    void helperFunc(TreeNode* root , vector<string>& answer, vector<int> &output){
        if(root==NULL){
            return ;
        }
        if(!root->left && !root->right){
            output.push_back(root->val);
            string path = "";
            for(int i = 0; i < output.size() - 1; i++){
                path += to_string(output[i]) + "->";
            }
            path += to_string(output.back());
            answer.push_back(path);
            output.pop_back();
            return ;
        }
        else {
            output.push_back(root->val);
            helperFunc(root->left,answer,output);
            helperFunc(root->right,answer,output);
            output.pop_back();
            return ;
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        vector<int> output;
        helperFunc(root,answer,output);
        return answer;
    }
};