// https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postorder-traversal-iterative


//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Traversals{
    public:
    vector<int> pre,post,in;
    
    void allTraversals(Node* root){
        stack<pair<Node*,int>> stk;
        stk.push({root,1});
        while(!stk.empty()){
            pair<Node*,int> p = stk.top();
            stk.pop();
            Node* curNode = p.first;
            int curNum = p.second;
            if(curNum == 1){
                pre.push_back(curNode->data);
                stk.push({curNode,curNum+1});
                if(curNode->left)
                    stk.push({curNode->left,1});
            }
            else if(curNum == 2){
                in.push_back(curNode->data);
                stk.push({curNode,curNum+1});
                if(curNode->right)
                    stk.push({curNode->right,1});
            }
            else {
                post.push_back(curNode->data);
            }
        }
    }
};

class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here
        Traversals sol;
        sol.allTraversals(root);
        return sol.post;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.postOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends