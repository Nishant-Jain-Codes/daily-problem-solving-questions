/*
Find Path in BST
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8

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

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data==data)
    {
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector<int>* leftans =getPath(root->left,data);
    if(leftans!=NULL)
    {
        leftans->push_back(root->data);
        return leftans;
    }
    else
    {
        vector<int>* rightans =getPath(root->right,data);
		if(rightans!=NULL)
        {
            rightans->push_back(root->data);
            return rightans;
        }
        else
        {
            return NULL;
        }
		
    }
}
