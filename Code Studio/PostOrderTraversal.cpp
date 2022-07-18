/*


*/


// solution 


/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/
void postorderTraversal(TreeNode* root,vector<int>& post)
{
    if(root==NULL)
    {
       return ;
    }
    postorderTraversal(root->left,post);
    postorderTraversal(root->right,post);
    post.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int> post;
    postorderTraversal(root,post);
    return post;
    
}
