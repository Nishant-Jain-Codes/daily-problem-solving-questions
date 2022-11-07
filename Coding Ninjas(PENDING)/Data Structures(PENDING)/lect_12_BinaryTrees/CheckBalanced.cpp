/*

Check Balanced
Send Feedback
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format
The first and only line of output contains true or false.
Constraints
Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

// solution 

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
pair<int,bool> isBalancedHelper(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair<int,bool>ans;
        ans.first=0;
        ans.second=true;
        return ans;
    }
    pair<int,bool> leftAns = isBalancedHelper(root->left);
    pair<int,bool> rightAns = isBalancedHelper(root->right);
    int     lh=leftAns.first;
    bool    lb=leftAns.second;//left balance
    int     rh=rightAns.first;
    bool    rb=rightAns.second;//right balance
    int 	height = 1+max(lh,rh);
    bool 	balanced = lb&&rb&&(abs(lh-rh)<=1);
    pair<int,bool>ans;
    ans.first=height;
    ans.second=balanced;
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    return isBalancedHelper(root).second;
}
