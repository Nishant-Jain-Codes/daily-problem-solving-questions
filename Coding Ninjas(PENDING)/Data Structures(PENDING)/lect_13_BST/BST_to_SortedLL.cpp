/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10

*/


// solution 

/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
pair<Node<int>*,Node<int>*>  constructLinkedList_better_helper(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>*> ans;
        ans.first=NULL;
        ans.second=NULL;
        return ans;
    }
    Node<int>* rootnode = new Node<int>(root->data);
    pair<Node<int>*,Node<int>*> leftans = constructLinkedList_better_helper(root->left);
    pair<Node<int>*,Node<int>*> rightans = constructLinkedList_better_helper(root->right);
    if(leftans.first!=NULL)
    {
       	leftans.second->next=rootnode;
        rootnode->next=rightans.first;
        if(rightans.first!=NULL)
        	return {leftans.first,rightans.second};
        else
            return {leftans.first,rootnode};
    }
    else
    {
        rootnode->next=rightans.first;
        if(rightans.first==NULL)
        	return {rootnode,rootnode};
        else
            return {rootnode,rightans.second};
    }
    
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root)
{
    return constructLinkedList_better_helper(root).first;
}
