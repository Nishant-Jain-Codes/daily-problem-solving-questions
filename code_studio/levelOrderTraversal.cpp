/*

Problem Statement
You have been given a Binary Tree of integers. You are supposed to return the level order traversal of the given tree.
For Example:
For the given binary tree

The level order traversal will be {1,2,3,4,5,6,7}.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case contains elements of the tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

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

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null(-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
Print all the nodes in level order traversal separated by a single space.
For each test case, print the output in a new line.
Note :
You do not need to print anything; it has already been taken care of.
Constraints:
1 <= T <= 100
0 <= N <= 1000
0 <= data <= 10^6 and data != -1
Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “data” is the value of the binary tree node.

Time Limit: 1sec
Sample Input 1:
3
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 -1 -1
1 3 -1 2 -1 -1 -1
Sample Output 1:
1 2 3 4 5 6 7
1 2 3
1 3 2
Explanation Of Sample Input 1:
 For the first test case, {1} is at level 1 and {2,3} are at level 2 and {4,5,6} are at level 3 and {7} is at level 4. So combinations of all levels are {1, 2, 3 ,4, 5, 6, 7}.

For the second test case, {1} is at level 1 and {2,3} are at level 2. So combinations of level are {1, 2, 3}.

For the third test case, {1} is at level 1 and {3} is at level 2 and {2} is at level 3. So combinations of all levels are {1,3,2}.
Sample Input 2:
2
2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1
1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1  
Sample Output 2:
2 7 5 2 6 9 5 11 4
1 2 3 4 5 6
Explanation Of Sample Input 2:
For the first test case, {2} is at level 1 and {7,5} are at level 2 and {2,6,9} are at level 3 and {5,11,4} are at level 4. So combinations of all levels are {2, 7, 5, 2, 6, 9, 5, 11, 4}.

For the second test case, {1} is at level 1 and {2,3} are at level 2 and {4,5,6} are at level 3. So combinations of all levels are {1, 2, 3, 4, 5, 6}.
*/

// solution
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<queue>
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root==NULL)
    {    
        vector<int> ans;
       return ans;
    }
    queue<BinaryTreeNode<int> *> pendingnode;
    vector<int>ans;
    pendingnode.push(root);
    pendingnode.push(NULL);
    ans.push_back(root->val);
    while(!pendingnode.empty())
    {
        BinaryTreeNode<int> * front = pendingnode.front();
        pendingnode.pop();
        
       if(front->left!=NULL)
       {
           ans.push_back(front->left->val);
           pendingnode.push(front->left);
       }
        if(front->right!=NULL)
       {
           ans.push_back(front->right->val);
           pendingnode.push(front->right);
       }
        if(pendingnode.front()==NULL)
        {
            pendingnode.pop();
            if(!pendingnode.empty())
            {
                pendingnode.push(NULL);
            }
        }
        
    }
    return ans;
}
