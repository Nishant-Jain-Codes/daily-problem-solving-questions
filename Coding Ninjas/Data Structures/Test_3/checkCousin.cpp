/*

Check cousins
Send Feedback
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p 
Line 3 : Integer value of q
Output format :
true or false
Constraints :
1 <= N <= 10^5
Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true

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
#include<queue>
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
	if(root==NULL)
    {
        return false;
    }
    bool hasP = false;
    bool hasQ = false;
    queue<BinaryTreeNode<int> *> restNodes;
    restNodes.push(root);
    restNodes.push(NULL);
    while(!restNodes.empty())
    {
        BinaryTreeNode<int>* front = restNodes.front();
        restNodes.pop();
       	
        if(front->left!=NULL)
        {
            restNodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            restNodes.push(front->right);
        }
        if(front->data==p)
        {
            hasP=true;
        }
        else if(front->data==q)
        {
            hasQ=true;
        }
        
         if(restNodes.front()==NULL)
        {
		restNodes.pop();
        	if(!restNodes.empty())
            {
                restNodes.push(NULL);
        		if(hasP&&hasQ)
                {
                    return true;
                }
                else{
                    hasQ=false;
                	hasP=false;
                }
            }
        
        }
        
    }
    return hasP&&hasQ;
}
