/*
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7
*/

//solution 

void treeToArr(BinaryTreeNode<int>*root,vector<int>&v)
{
    if(root==NULL)
        return;
    treeToArr(root->left,v);
    v.push_back(root->data);
    treeToArr(root->right,v);
    
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {

	vector<int> v;
    treeToArr(root,v);
    int si=0;
    int ei=v.size()-1;
    while(si<ei)
    {
        if(v[si]+v[ei]>s)
            ei--;
        else if(v[si]+v[ei]<s)
            si++;
        else
        {
            cout<<v[si]<<" "<<v[ei]<<endl;
            si++;
            ei--;
        }
    }
}
