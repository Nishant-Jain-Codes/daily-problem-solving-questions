// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        string serializedTree ="";
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(!curNode)
                {
                    serializedTree.append("#,");
                }
            else{
                serializedTree.append(to_string(curNode->val)+',');
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return serializedTree;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                curNode->left=NULL;
            }
            else{
                curNode->left = new TreeNode(stoi(str));
                q.push(curNode->left);
            }
            getline(s,str,',');
            if(str == "#"){
                curNode->right=NULL;
            }
            else{
                curNode->right = new TreeNode(stoi(str));
                q.push(curNode->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));