/*
Check if a Binary Tree is BST
Send Feedback
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false

*/

// solution 
// method o(N)
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
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

***********************************************************/
class isBSTreturn{

    public:
    bool isBST;
    int minmum;
    int maxmum;
    isBSTreturn(bool isBST,int minmum,int maxmum)
    {
        this->isBST =isBST;
        this->minmum   = minmum;
        this->maxmum   = maxmum;
    }
};
isBSTreturn isBST_better_helper(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {	
        int INT_MIN=-2147483647;
        int INT_MAX=2147483647;
        isBSTreturn ans(true,INT_MAX,INT_MIN);
        return ans;
    }   
    isBSTreturn leftAns = isBST_better_helper(root->left);
    isBSTreturn rightAns = isBST_better_helper(root->right);
    int maxmum = max(root->data,max(leftAns.maxmum,rightAns.maxmum));
    int minmum = min(root->data,min(leftAns.minmum,rightAns.minmum));
    bool isBST = (leftAns.maxmum<root->data)&&(rightAns.minmum>=root->data)&&leftAns.isBST&&rightAns.isBST;
    isBSTreturn ans(isBST,minmum,maxmum);
    return ans;
}
bool isBST(BinaryTreeNode<int> *root)
{
    return isBST_better_helper(root).isBST;
}
//method o(n^2)
int maximum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return -2147483647;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return 2147483647;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root,int rootdata=0) {
	// Write your code here
    if(root==NULL)
    {
        return true;
    }
    int leftmax=maximum(root->left);
    int rightmin=minimum(root->right);
    bool output = (root->data>leftmax)&&(root->data<=rightmin)&&(isBST(root->left))&&(isBST(root->right));
// method o(N)
  
  bool isBST_topdown(BinaryTreeNode<int> *root , int minimum = INT_MAX , int maximum = INT_MIN)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data<minimum||root->data>maximum)
    {
        return false;
    }
    bool isLeftOk = isBST_topdown(root->left,minimum,root->data);
    bool isRightOk = isBST_topdown(root->right,root->data,maximum);
    return isLeftOk&&isRightOk;
}

