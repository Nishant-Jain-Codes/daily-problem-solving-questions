// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(!q.empty()){
            int size = q.size();
            long long minNo = q.front().second;
            long long first, last;
            for(int i=0;i<size;i++){
                long long cur_id = q.front().second - minNo;
                TreeNode* curNode = q.front().first;
                q.pop();
                if(i==0)
                    first=cur_id;
                if(i==size-1)
                    last = cur_id;
                if(curNode->left)
                    q.push({curNode->left,(2*cur_id)});
                if(curNode->right)
                    q.push({curNode->right,(2*cur_id)+1});
            }
            maxWidth = max(maxWidth,(int)(last-first+1));
        }
        return maxWidth;
    }
};
