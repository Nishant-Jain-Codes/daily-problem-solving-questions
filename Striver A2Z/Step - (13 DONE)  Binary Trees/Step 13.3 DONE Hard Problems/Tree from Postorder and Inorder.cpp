// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=tree-from-postorder-and-inorder

//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
  Node* buildTreeHelper(int* inOrder, int* postOrder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    int rootValue = postOrder[postEnd];
    Node* root = new Node(rootValue);

    int rootIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == rootValue) {
            rootIndex = i;
            break;
        }
    }

    int leftSubtreeSize = rootIndex - inStart;

    root->left = buildTreeHelper(inOrder, postOrder, inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
    root->right = buildTreeHelper(inOrder, postOrder, rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);

    return root;
}

Node* buildTree(int* inOrder, int* postOrder, int n) {
    if (n == 0) {
        return NULL;
    }

    return buildTreeHelper(inOrder, postOrder, 0, n - 1, 0, n - 1);
}
