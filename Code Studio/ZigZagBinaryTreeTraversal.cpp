/*
Problem Statement
Given a binary tree, return the zigzag level order traversal of the nodes' values of the given tree. Zigzag traversal means starting from left to right, then right to left for the next level and then again left to right and so on in an alternate manner.
For Example:
For the binary tree in the image below

The zigzag traversal will be {{2}, {5, 7}, {2, 6, 9}, {4, 11, 5}}.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases are as follows.

The only line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place. So -1 would not be a part of the tree nodes.

For example, the input for the tree depicted in the below image will be:

For example taking a tree:

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

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null(-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
For each test case, print the zigzag level order traversal of the given binary tree separated by single spaces.

Print the output of each test case in a separate line.
Note:
You don’t need to print anything, it has already been taken care of.
Constraints:
1 <= T <= 100
0 <= N <= 3000
0 <= val <= 10^5

Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “val” is the value of the binary tree node

Time Limit: 1 sec
Sample Input 1:
2
1 2 3 4 -1 -1 -1 -1 -1
1 -1 2 -1 -1
Sample Output 1:
1 3 2 4
1 2
Explanation Of Sample Input 1:
For the first test case, the zigzag level order traversal of the given binary tree will be {{1}, {3, 2}, {4}}.

For the second test case, the zigzag level order traversal of the given binary tree will be {{1}, {2}}.
Sample Input 2:
2
1 -1 -1
0 1 2 4 5 3 6 -1 -1 7 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
1
0 2 1 4 5 3 6 7 
Explanation Of Sample Input 2:
For the first test case, the zigzag level order traversal of the given binary tree will be {{1}}.

For the second test case, the zigzag level order traversal of the given binary tree will be {{0}, {2, 1}, {4, 5, 3, 6}, {7}}.
*/

// solution 

/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<stack>
vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if(root==NULL)
    {
        vector<int> ans;
        return ans;
    }
    vector<int> ans ;
    stack<TreeNode<int>*> s1,s2;
    s1.push(root);
   while(!s1.empty()||!s2.empty())
   {
       while(!s1.empty())
       {
           TreeNode<int>* top = s1.top();
           s1.pop();
           ans.push_back(top->data);
           if(top->left!=NULL)
           {
           s2.push(top->left);    
           }
           if(top->right!=NULL)
           {
             s2.push(top->right);  
           }
           
       }
       while(!s2.empty())
       {
            TreeNode<int>* top = s2.top();
           s2.pop();
           ans.push_back(top->data);
          
           if(top->right!=NULL)
           {
             s1.push(top->right);  
           }
            if(top->left!=NULL)
           {
           s1.push(top->left);    
           }
       }
   }
    return ans;
}
