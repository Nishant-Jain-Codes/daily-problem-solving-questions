/*
Construct Tree from Postorder and Inorder
Send Feedback
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

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
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
2 9 3 6 10 5 
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
BinaryTreeNode<int>* buildTreeHelper(int *postorder,  int *inorder, int inS,int inE, int posS,int posE)
{
    if(inS>inE)
    {
        return NULL;
    }
    int rootdata = postorder[posE];
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
    int LinS=inS;//
    int LinE=rootindex-1;//
    int LposS=posS;//
    int LposE=LinE+LposS-LinS;
    int RinS=rootindex+1;//
    int RinE=inE;//
    int RposS=LposE+1;//
    int RposE=posE-1;//
    root->left= buildTreeHelper(postorder,inorder,LinS,LinE,LposS,LposE);
    root->right= buildTreeHelper(postorder,inorder,RinS,RinE,RposS,RposE);
    return root;
    
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    int inS = 0 ;
    int inE = inLength-1;
    int posS = 0 ;
    int posE = postLength -1;
    return buildTreeHelper(postorder,inorder,inS,inE,posS,posE);
}
