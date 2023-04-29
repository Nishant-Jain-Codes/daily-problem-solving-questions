// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* buildTreeHelper(vector<int>& postOrder, vector<int>& inOrder ,int in_si,int in_ei,int post_si,int post_ei){
        if(in_si > in_ei || post_si > post_ei || post_si < 0 || post_si >= postOrder.size() || post_ei < 0 || post_ei >= postOrder.size() || in_si < 0 || in_ei >= inOrder.size() || in_si > in_ei)
            return NULL;
        int root_val = postOrder[post_ei];
        int in_left_si = in_si;
        int in_root_idx  = 0;
        for(int i=in_si;i<=in_ei;i++){
            if(inOrder[i]==root_val)
                {
                    in_root_idx = i;
                    break;
                }
        }
        int in_left_ei = in_root_idx -1;;
        int in_right_si = in_root_idx+1; 
        int in_right_ei = in_ei;
        int post_left_si = post_si;
        int post_left_ei = post_left_si + (in_left_ei - in_left_si);
        int post_right_si = post_left_ei + 1;
        int post_right_ei = post_ei-1;
        TreeNode * root = new TreeNode(root_val);
        root->left = buildTreeHelper(postOrder,inOrder,in_left_si,in_left_ei,post_left_si,post_left_ei);
        root->right = buildTreeHelper(postOrder,inOrder,in_right_si,in_right_ei,post_right_si,post_right_ei);
        return root;
    }
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        if(postOrder.size()==0||inOrder.size()==0 || postOrder.size()!=inOrder.size())
            return NULL;
        int in_si = 0;
        int in_ei = inOrder.size()-1;
        int post_si=0;
        int post_ei=postOrder.size()-1;
        return buildTreeHelper(postOrder,inOrder,in_si,in_ei,post_si,post_ei);

    }
};