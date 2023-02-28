// https://practice.geeksforgeeks.org/problems/postorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postorder-traversal




//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
void postOrder(Node* root,vector<int> &ans)
{
    if(root==NULL)
        return;
    postOrder(root->left,ans);
    postOrder(root->right,ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  postOrder(root,ans);
  return ans;
}