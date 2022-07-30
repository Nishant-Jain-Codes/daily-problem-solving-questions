/*
Inorder Traversal
BasicAccuracy: 60.29%Submissions: 100k+Points: 1
Given a Binary Tree, find the In-Order Traversal of it.

Example 1:

Input:
       1
     /  \
    3    2
Output: 3 1 2

Example 2:

Input:
        10
     /      \ 
    20       30 
  /    \    /
 40    60  50
Output: 40 20 60 10 50 30

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrder() that takes root node of the tree as input and returns a list containing the In-Order Traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

// solution 

void inOrder(Node* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);
        
    }
 vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        inOrder(root,ans);
        return ans;
    }
