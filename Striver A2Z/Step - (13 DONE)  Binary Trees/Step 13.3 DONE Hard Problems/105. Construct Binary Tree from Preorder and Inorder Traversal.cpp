https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preOrder, vector<int>& inOrder ,int in_si,int in_ei,int pre_si,int pre_ei){
        if(in_si > in_ei || pre_si > pre_ei || pre_si < 0 || pre_si >= preOrder.size() || pre_ei < 0 || pre_ei >= preOrder.size() || in_si < 0 || in_ei >= inOrder.size() || in_si > in_ei)
            return NULL;
        int root_val = preOrder[pre_si];
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
        int pre_left_si = pre_si + 1;
        int pre_left_ei = pre_left_si + (in_left_ei - in_left_si);
        int pre_right_si = pre_left_ei + 1;
        int pre_right_ei = pre_ei;
        TreeNode * root = new TreeNode(root_val);
        root->left = buildTreeHelper(preOrder,inOrder,in_left_si,in_left_ei,pre_left_si,pre_left_ei);
        root->right = buildTreeHelper(preOrder,inOrder,in_right_si,in_right_ei,pre_right_si,pre_right_ei);
        return root;
    }
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        if(preOrder.size()==0||inOrder.size()==0 || preOrder.size()!=inOrder.size())
            return NULL;
        int in_si = 0;
        int in_ei = inOrder.size()-1;
        int pre_si=0;
        int pre_ei=preOrder.size()-1;
        return buildTreeHelper(preOrder,inOrder,in_si,in_ei,pre_si,pre_ei);

    }
};
