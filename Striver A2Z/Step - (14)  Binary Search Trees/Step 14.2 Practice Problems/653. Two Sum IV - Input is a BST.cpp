// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/


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
class BSTIterator{
    stack<TreeNode*> stk;
    bool reverse;
    public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse=isReverse;
        pushALL(root);
    }
    bool hasNext(){
        return !stk.empty();
    }
    int next(){
        TreeNode * curNode = stk.top();
        stk.pop();
        if(!reverse)
            pushALL(curNode->right);
        else 
            pushALL(curNode->left);
        return curNode->val;
    }
    private:
    void pushALL(TreeNode* node){
        while(node){
            stk.push(node);
            if(reverse)
                node = node->right;
            else 
                node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
    if (!root)
        return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    if (!l.hasNext() || !r.hasNext())
        return false;
    int i = l.next();
    int j = r.next();
    while (i < j) {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
    }
};