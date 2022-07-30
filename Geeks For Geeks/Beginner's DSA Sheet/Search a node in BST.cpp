/*
Search a node in BST
BasicAccuracy: 55.04%Submissions: 48375Points: 1
Given a Binary Search Tree and a node value X, find if the node with value X is present in the BST or not.


Example 1:

Input:         2
                \
                 81 
               /    \ 
             42      87 
              \       \ 
               66      90 
              / 
            45
X = 87
Output: 1
Explanation: As 87 is present in the
given nodes , so the output will be
1.
Example 2:

Input:      6
             \ 
              8 
             / \ 
            7   9
X = 11
Output: 0
Explanation: As 11 is not present in 
the given nodes , so the output will
be 0.

Your Task:
You don't need to read input or print anything. Complete the function search()which returns true if the node with value x is present in the BSTelse returns false.


Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(1).


Constraints:
1 <= Number of nodes <= 105
*/

// solution 

Node* search2(Node* root,int x)
{
    if(root==NULL)
        return root;
    if(root->data==x)
        return root;
    else if(root->data>x)
        return search2(root->left,x);
    else 
        return search2(root->right,x);
}
bool search(Node* root, int x) {
    // Your code here
    Node* ans = search2(root,x);
    if(ans)
        return true;
    else 
        return false;
}
