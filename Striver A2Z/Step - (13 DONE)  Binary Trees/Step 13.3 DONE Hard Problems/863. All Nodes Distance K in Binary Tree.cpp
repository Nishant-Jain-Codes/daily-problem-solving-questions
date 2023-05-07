// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/


/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void mapParent(TreeNode* root , unordered_map<TreeNode* , TreeNode*> & parentMapping){
        queue<TreeNode*> q;
        q.push(root);
        parentMapping[root]=NULL;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ;i<size;i++){
                TreeNode* curTreeNode = q.front();
                q.pop();
                if(curTreeNode->left)
                    {
                        q.push(curTreeNode->left);
                        parentMapping[curTreeNode->left]=curTreeNode;
                    }
                if(curTreeNode->right)
                    {
                        q.push(curTreeNode->right);
                        parentMapping[curTreeNode->right]=curTreeNode;
                    }
            }
        }
    
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target)
            return {};
        vector<int> answer;
        queue<pair<TreeNode*,int>> q;
        unordered_map<TreeNode*,bool> visited;
        unordered_map<TreeNode*,TreeNode*> parent;
        mapParent(root,parent);
        q.push({target,0});
        visited[target]=true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curNode = q.front().first;
                int curDist = q.front().second;
                q.pop();
                if(curDist==k)
                    answer.push_back(curNode->val);
                if(curNode->left && !visited[curNode->left]){
                    visited[curNode->left]=true;
                    q.push({curNode->left,curDist+1});
                }
                if(curNode->right && !visited[curNode->right]){
                    visited[curNode->right]=true;
                    q.push({curNode->right,curDist+1});
                }
                if(parent[curNode] && !visited[parent[curNode]]){
                    visited[parent[curNode]]=true;
                    q.push({parent[curNode],curDist+1});
                }
            }
        }
        return answer;
    }
};