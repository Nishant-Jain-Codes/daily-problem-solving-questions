/*
Code: Construct Tree from Preorder and Inorder
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 

*/


// solution 

/***********************************************************
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
BinaryTreeNode<int>* buildTreeHelper(int *preorder,  int *inorder, int inS,int inE, int preS,int preE)
{
    if(inS>inE)
    {
        return NULL;
    }
    int rootdata = preorder[preS];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    int rootindex = -1;
    for(int i = inS;i<=inE;i++)
    {
        if(inorder[i]==rootdata)
        {
            rootindex = i;
            break;
        }
    }
    int LinS=inS;
    int LinE=rootindex-1;
    int LpreS=preS+1;
    int LpreE=LinE+LpreS-LinS;
    int RinS=rootindex+1;
    int RinE=inE;
    int RpreS=LpreE+1;
    int RpreE=preE;
    root->left=buildTreeHelper(preorder,inorder,LinS,LinE,LpreS,LpreE);
    root->right=buildTreeHelper(preorder,inorder,RinS,RinE,RpreS,RpreE);
    return root;
    
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    int inS = 0 ;
    int inE = inLength-1;
    int preS = 0 ;
    int preE = preLength -1;
    return buildTreeHelper(preorder,inorder,inS,inE,preS,preE);
}
