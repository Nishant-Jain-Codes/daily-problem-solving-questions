/*
Level order traversal
EasyAccuracy: 49.61%Submissions: 100k+Points: 2
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

// solution 

vector<int> levelOrder(Node* root)
    {
      //Your code here
      if(root==NULL)
        {
            vector<int> ans;
            return ans;
        }
    queue<Node*> pendingNode;
    pendingNode.push(root);
    pendingNode.push(NULL);
    vector<int> ans;
    while(!pendingNode.empty())
    {
        Node* front = pendingNode.front();
        pendingNode.pop();
        ans.push_back(front->data);
        if(front->left!=NULL)
            pendingNode.push(front->left);
        if(front->right!=NULL)
            pendingNode.push(front->right);
        if(pendingNode.front()==NULL)
        {
            pendingNode.pop();
            if(!pendingNode.empty())
                pendingNode.push(NULL);
        }
    }
    return ans;
    }
