/*
Problem Statement
Ninja has been given a postorder and inorder traversal of a Binary Tree of type integer with ‘N’ nodes stored in an array/list ‘POST_ ORDER’ and ‘IN_ORDER’. Ninja has to create the binary tree using the given two arrays/lists and return the root of that tree.
Note:
Assume that the Binary Tree contains only unique elements.
For Example:
Let's assume: ‘IN_ORDER’ = [9, 3, 15, 20, 7]  and ‘POST_ORDER’= [9, 15, 7, 20, 3].
We get the following binary tree from Inorder and Postorder traversal:

Input Format
The first line of input contains an integer ‘T’ which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains an integer ‘N’ which represents the number of nodes in the Binary Tree.

The next line of each test case contains ‘N’ single space-separated integers, representing the Postorder traversal of the Binary Tree.

The next line of each test case contains ‘N’ single space-separated integers, representing the Inorder traversal of the Binary Tree.
Output Format :
For each test case, print the level order traversal of the Binary Tree. 

Print the output of each test case in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints :
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10000
1 <=  ‘POST_ORDER[i]’ , ‘IN_ORDER[i]’ <= 100000  

Where ‘T’ denotes the number of test cases, ‘N’ denotes the number of nodes in the tree, and  ‘POST_ORDER[i]’ and ‘IN_ORDER[i]’ represent the value of the node in Postorder-traversal and Inorder-traversal of the Binary Tree respectively.

Time Limit: 1 second
Sample Input 1:
1
7
4 5 2 6 7 3 1
4 2 5 1 6 3 7
Sample Output 1:
1 2 3 4 5 6 7
Explanation for Sample Output 1:
For sample test case 1: 

We get the following Binary Tree from the given Inorder and Postorder traversal:

Sample Input 2:
1
6
2 9 3 6 10 5
2 6 3 9 5 10
Sample Output 2:
5 6 10 2 3 9
*/

// solution 

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* getTreeFromPostorderAndInorder_helper(vector<int>& postOrder, vector<int>& inOrder,int pS,int pE,int iS,int iE)
{
    if(pS>pE)
    {
        return NULL;
    }
    int rootdata = postOrder[pE];
    int rootindex=-1;
    for(int i = iS;i<=iE;i++)
    {
        if(inOrder[i]==rootdata)
        {
            rootindex=i;
            break;
        }
    }
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int lpS=pS;
    int liS=iS;
    int liE=rootindex-1;
    int lpE=liE-liS+lpS;
    int rpS=lpE+1;
    int rpE=pE-1;
    int riS=rootindex+1;
    int riE=iE;
    TreeNode<int>* leftAns = getTreeFromPostorderAndInorder_helper(postOrder,inOrder,lpS,lpE,liS,liE);
    TreeNode<int>* rightAns = getTreeFromPostorderAndInorder_helper(postOrder,inOrder,rpS,rpE,riS,riE);
    root->left=leftAns;
    root->right=rightAns;
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    return getTreeFromPostorderAndInorder_helper(postOrder,inOrder,0,postOrder.size()-1,0,inOrder.size()-1);
}
