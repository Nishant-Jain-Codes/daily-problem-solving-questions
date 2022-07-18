/*

Longest Leaf to root path
Send Feedback
Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 1 : Binary Tree 1 (separated by space)

Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
9
3
6
5

*/

// solution 

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
int height(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL)
    {	
        vector<int>* ans = new vector<int>();
        return ans;
    }
	if(root->left==NULL&&root->right==NULL)
    {
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    int lH=0,rH=0;
    if(root->left!=NULL)
    {
        lH=height(root->left);
    }
    if(root->right!=NULL)
    {
        rH=height(root->right);
    }
    if(lH>rH)
    {
        vector<int>* left = longestPath(root->left);
        left->push_back(root->data);
        return left;
    }
    else
    {
        vector<int>* right = longestPath(root->right);
        right->push_back(root->data);
        return right;
    }
}
