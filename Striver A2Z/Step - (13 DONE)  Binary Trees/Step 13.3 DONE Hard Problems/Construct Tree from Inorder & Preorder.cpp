// https://practice.geeksforgeeks.org/problems/construct-tree-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=construct-tree

//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTreeHelper(int* preOrder, int* inOrder ,int in_si,int in_ei,int pre_si,int pre_ei){
        if(in_si > in_ei || pre_si > pre_ei )
            return NULL;
        int root_val = preOrder[pre_si];
        int in_left_si = in_si;
        int in_root_idx  = 0;
        for(int i=in_si;i<=in_ei;i++){
            if(inOrder[i]==root_val)
                {
                    in_root_idx = i;
                    break;
                }
        }
        int in_left_ei = in_root_idx -1;;
        int in_right_si = in_root_idx+1; 
        int in_right_ei = in_ei;
        int pre_left_si = pre_si + 1;
        int pre_left_ei = pre_left_si + (in_left_ei - in_left_si);
        int pre_right_si = pre_left_ei + 1;
        int pre_right_ei = pre_ei;
        Node * root = new Node(root_val);
        root->left = buildTreeHelper(preOrder,inOrder,in_left_si,in_left_ei,pre_left_si,pre_left_ei);
        root->right = buildTreeHelper(preOrder,inOrder,in_right_si,in_right_ei,pre_right_si,pre_right_ei);
        return root;
    }
    Node* buildTree(int inOrder[],int preOrder[], int n)
    {
        // Code here
        if(n==0)
            return NULL;
        int in_si = 0;
        int in_ei = n-1;
        int pre_si=0;
        int pre_ei=n-1;
        return buildTreeHelper(preOrder,inOrder,in_si,in_ei,pre_si,pre_ei);

    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends