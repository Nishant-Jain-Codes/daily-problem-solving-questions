/*
Given a Binary Tree of size N, your task is to complete the function countNonLeafNodes(), that should return the count of all the non-leaf nodes of the given binary tree.

Example:

Input: 
Image
Output:
2
Explanation:
Nodes 1 and 2 are the only non leaf nodes.
Your Task:
You don't need to take input or print anything. Your task is to complete the function countNonLeafNodes() that takes root as input and returns the number of non leaf nodes in the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
*/

// solution 

 int countNonLeafNodes(Node* root) {
        // Code here
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return 0;
        else
            return 1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right);
            
    }
