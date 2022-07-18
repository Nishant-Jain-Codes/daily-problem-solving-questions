/*
Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/

// solution 

/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

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
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
#include<queue>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    {	
        vector<Node<int>*> ans;
        ans.push_back(NULL);
        return ans;
    }
    vector<Node<int>*> ans;
    queue<BinaryTreeNode<int>*> pendingnode;
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    pendingnode.push(root);
    pendingnode.push(NULL);
    while(!pendingnode.empty())
    {
        BinaryTreeNode<int>* front = pendingnode.front();
        pendingnode.pop();
        if(front!=NULL)
        {
            if(head==NULL)
            {
                Node<int>* newnode = new Node<int>(front->data);
                head=newnode;
                tail=newnode;
            }
            else
            {
                Node<int>* newnode = new Node<int>(front->data);
                tail->next=newnode;
                tail=tail->next;
            }
            if(front->left!=NULL)
            {
                pendingnode.push(front->left);
            }
            if(front->right!=NULL)
            {
                pendingnode.push(front->right);
            }
            
        }
        else
        {
            ans.push_back(head);
            head=NULL;
            tail=NULL;
            if(!pendingnode.empty())
            {
                pendingnode.push(NULL);
            }
        }
    }
    return ans;
}
