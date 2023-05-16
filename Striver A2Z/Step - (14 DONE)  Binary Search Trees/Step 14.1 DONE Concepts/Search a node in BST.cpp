https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-a-node-in-bst



// Function to searcha node in BST.
Node* search2(Node* root,int x)
{
    if(root==NULL)
        return root;
    if(root->data==x)
        return root;
    else if(root->data>x)
        return search2(root->left,x);
    else 
        return search2(root->right,x);
}
bool search(Node* root, int x) {
    // Your code here
    Node* ans = search2(root,x);
    if(ans)
        return true;
    else 
        return false;
}