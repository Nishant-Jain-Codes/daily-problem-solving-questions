/*
Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2

*/

// solution 
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
int INT_MIN = -2147483647;
int INT_MAX = 2147483647;
class solution
{
	public:
    
    bool isBST;
    int height;
    int MAX;
    int MIN;
    solution(bool isBST,int height,int MAX,int MIN)
    {
        this->isBST= isBST;
        this->height=height;
        this->MAX=MAX;
        this->MIN=MIN;
    }
    
};
solution largestBSTSubtreeHelper(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        solution ans(true,0,INT_MIN,INT_MAX);
        return ans;
    }
    solution leftAns = largestBSTSubtreeHelper(root->left);
    solution rightAns = largestBSTSubtreeHelper(root->right);
    int MIN = min(root->data,min(leftAns.MIN,rightAns.MIN));
    int MAX = max(root->data,max(leftAns.MAX,rightAns.MAX));
    int height;
    bool isBSTfinal =leftAns.isBST&&rightAns.isBST&&(root->data>leftAns.MAX&&root->data<=rightAns.MIN);
    if(isBSTfinal)
    {
        height = 1+max(leftAns.height,rightAns.height);
    }
    else
    {   
        height = max(leftAns.height,rightAns.height);
    }
    return {isBSTfinal,height,MAX,MIN};
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return largestBSTSubtreeHelper(root).height;
}
