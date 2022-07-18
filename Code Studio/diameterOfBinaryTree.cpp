/*
Problem Statement
You are given a Binary Tree. You are supposed to return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two end nodes in a tree.
Note :
The number of edges between two nodes represents the length of the path between them.
For Example :
For the given binary tree

Nodes in the diameter are highlighted. The length of the diameter, i.e., the path length, is 6.
Input Format :
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases are as follows.

The first line of each test case contains elements of the tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

For Example, the input for the tree depicted in the above image would be :

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
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format :
Print an integer that denotes the length of the diameter of the given binary tree.

Print the output of each test case in a new line.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
0 <= N <= 10^5
1 <= data <= 10^4

Where ‘N’ is the total number of nodes in the binary tree, and 'data' is the value of the binary tree node.

Time Limit: 1 sec
Sample Input 1 :
2
1 2 3 4 7 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 -1 -1
Sample Output 1 :
3
2
Explanation Of Sample Input 1 :
Test Case 1: The binary tree in the given test case will look like

The length of the diameter of the above tree is the length of the path between nodes 4 and 3, i.e., 4->2->1->3. Hence the output will be 3.

Test Case 2: The binary tree in the given test case will look like

The length of the diameter of the above tree is the length of the path between nodes 2 and 3, i.e., 2.
Sample Input 2 :
2
2 4 -1 5 -1 -1 -1
1 4 2 -1 -1 -1 3 -1 -1
Sample Output 2 :
2
3
*/

// solution 

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
pair<int,int> HeightAndDiameter(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    pair<int,int> leftans = HeightAndDiameter(root->left);
    pair<int,int> rightans = HeightAndDiameter(root->right);
    int height = 1 + max(leftans.first,rightans.first);
    int diameter = max(leftans.first+rightans.first,max(leftans.second,rightans.second));
    return {height,diameter};
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    return HeightAndDiameter(root).second;
}
