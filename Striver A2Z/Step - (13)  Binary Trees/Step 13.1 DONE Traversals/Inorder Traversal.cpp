// https://practice.geeksforgeeks.org/problems/inorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inorder-traversal

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    
void inOrder(Node* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);
        
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        inOrder(root,ans);
        return ans;
    }


};