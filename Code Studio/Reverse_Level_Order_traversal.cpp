/*
Problem Statement
You have been given a Binary Tree of integers. You are supposed to return the reverse of the level order traversal.
For Example:
For the given binary tree

The reverse level order traversal will be {7,6,5,4,3,2,1}.
Input Format:
The first line contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

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
Print all the nodes in reverse level order traversal separated by a single space.
Note :
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
0 <= N <= 5 * 10^5
0 <= data <= 10^5 and data != -1

Where ‘N’ is the total number of nodes in the binary tree, and 'data' is the value of the binary tree node.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Sample Output 1:
7 6 5 4 3 2 1
Explanation Of Sample Input 1:
Start with the bottom of the tree, i.e. 7, and traverse in the tree in the reverse direction of level order, i.e., bottom to top and right to left. So, the reverse level order traversal will be {7,6,5,4,3,2,1}.
Sample Input 2:
2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
4 11 5 9 6 2 5 7 2
Explanation Of Sample Input 2:
Traverse the tree in the reverse direction of level order, i.e., bottom to top and right to left. So reverse level order traversal will be {4,11,5,9,6,2,5,7,2}.

*/


//  solution 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<stack>
#include<queue>
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    if(root==NULL)
    {
        vector<int>ans;
        return ans;
    }
    queue<TreeNode<int>*> pendingnode ;
    stack<int> ans;
    pendingnode.push(root);
    while(!pendingnode.empty())
    {
        TreeNode<int>* front = pendingnode.front();
        pendingnode.pop();
        ans.push(front->val);
        if(front->left!=NULL)
        {
            pendingnode.push(front->left);
        }
        if(front->right!=NULL)
        {
            pendingnode.push(front->right);
        }
    }
    vector<int>answer;
    while(!ans.empty())
    {
        answer.push_back(ans.top());
        ans.pop();
    }
    return answer;
}
