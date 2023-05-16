// https://leetcode.com/problems/binary-search-tree-iterator/description/

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
class BSTIterator {
private:
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while (temp) {
            stk.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        if (!hasNext())
            return -1;
        TreeNode* topNode = stk.top();
        stk.pop();
        int ans = topNode->val;
        TreeNode* temp = topNode->right;
        while (temp) {
            stk.push(temp);
            temp = temp->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */