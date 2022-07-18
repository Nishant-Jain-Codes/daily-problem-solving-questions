/*
Problem Statement
Given a binary tree. You need to check if it is a height-balanced binary tree.
Height of a tree is the maximum number of nodes in a path from the node to the leaf node.
An empty tree is a height-balanced tree. A non-empty binary tree is a height-balanced binary tree if
1. The left subtree of a binary tree is already the height-balanced tree.
2. The right subtree of a binary tree is also the height-balanced tree.
3. The difference between heights of left subtree and right subtree must not more than ‘1’.
Consider this binary tree:

Consider subtree at Node ( 7 ) 
Left subtree height is ‘0’ and right subtree height is ‘0’, the absolute height difference is ‘0-0 = 0’ and ‘0’ is not more than ‘1’ so subtree at Node ( 7 ) is a height-balanced binary tree. 
Same for subtrees at Nodes ( 5, 6 ). 

Consider subtree at Node ( 4 ) 
Left subtree height is ‘1’ and right subtree height is ‘0’, the absolute height difference is ‘1-0 = 1’ and ‘1’ is not more than ‘1’ so subtree at Node ( 4 ) is a height-balanced binary tree.
Same for subtree at Node ( 3)

Consider subtree at Node ( 2 ) 
Left subtree height is ‘2’ and right subtree height is ‘1’, the absolute height difference is ‘2-1 = 1’ and ‘1’ is not more than ‘1’ so subtree at Node ( 2 ) is a height-balanced binary tree.

Consider subtree at Node ( 1 ) 
Left subtree height is ‘3’ and right subtree height is ‘2’, the absolute height difference is ‘3-2 = 1’ and ‘1’ is not more than ‘1’ so subtree at Node ( 1 ) is a height-balanced binary tree.

Because the root node ( 1 ) is a height-balanced binary tree, so the complete tree is height-balanced.
Note:
You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return ‘True’ or ‘False’.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘T’ lines represent the ‘T’ test cases.

The first line of input contains the elements of the tree in the level order form separated by a single space.
If any node does not have a left or right child, take -1 in its place. Refer to the example below.
Example:
Elements are in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image would be :

 1
 2 3
 4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1

Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null (-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 

The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
For every test case, return ‘True’ or ‘False’
Constraint :
1 <= T <= 100
1 <= N <= 3000
-10^9 <= data <= 10^9 and data != -1

Where ‘T’ represents the number of test cases, ‘N’ is the number of nodes in the tree, and data denotes ‘data’ contained in the node of a binary tree.

Time Limit: 1 sec
Sample Input 1:
2
1 2 3 4 -1 -1 -1 -1 5 -1 -1
1 2 3 4 -1 -1 5 -1 -1 -1 -1
Sample Output 1:
False
True
Explanation Of Sample Input 1:
Test case 1:

Consider the root  Node ( 1 ) 
Left subtree height is ‘3’ ( 1->2->4->5) and right subtree height is ‘1’ ( 1->3), the absolute height difference is ‘2-1 = 2’ and ‘2’ is more than ‘1’ so subtree at Node ( 1 ) is not a height-balanced binary tree.
Hence we return ‘False’.

Test case 2:

Consider the subtree at Node ( 4 ) 
Left subtree height is ‘0’ and right subtree height is ‘0’, the absolute height difference is ‘0-0 = 0’ and ‘0’ is not more than ‘1’ so subtree at Node ( 4 ) is a height-balanced binary tree.
Same for subtree at Node ( 5 ).

Consider the subtree at Node ( 2 ) 
Left subtree height is ‘1’ and right subtree height is ‘0’, the absolute height difference is ‘1-0 = 1’ and ‘1’ is not more than ‘1’ so subtree at Node ( 2 ) is a height-balanced binary tree.
Same for subtree at Node ( 3 ).

Consider the subtree at Node ( 1 ) 
Left subtree height is ‘2’ (1->2->4) and right subtree height is ‘2’ (1->3->5), the absolute height difference is ‘2-2 = 0’ and ‘0’ is not more than ‘1’ so subtree at Node ( 1 ) is a height-balanced binary tree.

Hence root node (1) is a height-balanced binary tree that’s why the complete tree is a height-balanced binary tree. 
Hence we return ‘True’.
Sample Input 2:
2
1 2 3 -1 -1 -1 -1
1 2 3 4 5 -1 -1 -1 -1 6 -1 -1 -1 
Sample Output 2:
True
False
*/

// solution

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/
pair<int,bool>isBalancedBT_helper(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return {0,true};
    }
    pair<int,bool> leftans = isBalancedBT_helper(root->left);
    pair<int,bool> rightans = isBalancedBT_helper(root->right);
    int height=1+max(leftans.first,rightans.first);
    int isbalanced = (abs(leftans.first-rightans.first)<=1)&&leftans.second&&rightans.second;
    return {height,isbalanced};
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return isBalancedBT_helper(root).second;
}
