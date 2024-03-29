/*
Code: Construct BST from a Sorted Array
Send Feedback
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 
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
pair<Node<int>*,Node<int>*>  constructLinkedList_better_helper(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>*> ans;
        ans.first=NULL;
        ans.second=NULL;
        return ans;
    }
    Node<int>* head = NULL;
    Node<int>* rootnode = new Node<int>(root->data);
    pair<Node<int>*,Node<int>*> rootnodepair ;
    rootnodepair.first=rootnode;
    rootnodepair.second=NULL;
    pair<Node<int>*,Node<int>*> leftans = constructLinkedList_better_helper(root->left);
    pair<Node<int>*,Node<int>*> rightans = constructLinkedList_better_helper(root->right);
    if(leftans.first!=NULL)
    {
        leftans.second->next=rootnodepair.first;
        rootnodepair.first->next=rightans.first;
        head=leftans.second;
    }
    else
    {
        rootnodepair.first->next=rightans.first;
        head=rootnodepair.frist;
    }
    pair<Node<int>*,Node<int>*> ans;
    ans.first = head;
    ans.second = NULL;
    return ans;
    
}
Node<int>* constructLinkedList_better(BinaryTreeNode<int>* root)
{
    return constructLinkedList_better_helper(root).second;
}
