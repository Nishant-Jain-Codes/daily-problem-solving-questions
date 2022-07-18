/*
Problem Statement
You have been given a Binary Search Tree and a key value ‘X’, find if a node with value ‘X’ is present in the BST or not.
Note:
You may assume that duplicates do not exist in the tree.
For Example :
For the given tree shown below:

For the binary tree shown in the figure, if ‘X’ = 6, the output will be 1 as node value 6 is present in the BST.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases.

The first line of each test case contains elements of the tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains an integer ‘X’ which denotes the key value to be searched in the binary search tree.
Output Format:
For each test case, return true if the given key value exists in the binary search tree else return false.
Note:
You don't need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
0 <= DATA <= 10^4
0 <= X <= 10^4

Where 'DATA' is the value of the binary tree node.

Time limit: 1 sec
Sample Input 1:
1
8 5 10 3 6 -1 14 -1 -1 -1 -1 13 -1 -1 -1
6
5 -1 -1
5
Sample Output 1:
1
1
Explanation Of Sample Output 1:
In test case 1, the tree after the construction is shown below.

Thus we can see that 6 is present in the tree.

In test case 2, there is only one node and we need to find the node with value 5 and thus it is present.
Sample Input 2:
 2
79 42 80 36 49 -1 90 -1 -1 -1 -1 85 100 -1 -1 -1 -1
49
710 340 800 210 390 -1 810 -1 -1 350 -1 -1 900 -1 -1 -1 -1
100
Sample Output 2:
1 
0
Explanation Of Sample Input 2:
In test case 1, node value 49 is present in the tree hence output is 1.

In test case 2, node value 100 is not present in the tree so output is 0.
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

bool findNode(TreeNode <int> * root, int key) {
    // Write your code here.
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }
    else if(root->data>key)
    {
        return findNode(root->left,key);
    }
    else
    {
        return findNode(root->right,key);
    }
}
