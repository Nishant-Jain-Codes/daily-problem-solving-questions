// https://leetcode.com/problems/count-complete-tree-nodes/description/

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


// brute force O(N) space and O(N) time
class Solution {
public:
    int countNodes(TreeNode* root)  {
        if(!root)
            return 0;
        queue<pair<TreeNode* ,int>> q;
        q.push({root,1});
        int ans =0;
        while(!q.empty()){
            int size = q.size();
            int last;
            for(int i=0;i<size;i++){
                int cur_id = q.front().second;
                TreeNode* cur_node = q.front().first;
                q.pop();
                if(i==size-1)
                    last = cur_id;
                if(cur_node->left)
                    q.push({cur_node->left,2*cur_id });
                if(cur_node->right)
                    q.push({cur_node->right,2*cur_id +1 });
            }
            ans = last;
        }
        return ans;
    }
};
// optimal 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=0;
        TreeNode* temp = root->left;
        while(temp){
            lh++;
            temp=temp->left;
        }
        int rh=0;
        temp=root->right;
        while(temp){
            rh++;
            temp=temp->right;
        }
        if(lh==rh)
            return pow(2,lh+1) - 1;
        else 
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};