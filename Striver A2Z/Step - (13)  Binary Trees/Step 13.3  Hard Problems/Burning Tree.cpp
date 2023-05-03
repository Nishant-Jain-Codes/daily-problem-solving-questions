//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* mapParent(Node* root , unordered_map<Node* , Node*> & parentMapping,int target){
        queue<Node*> q;
        q.push(root);
        parentMapping[root]=NULL;

        Node* targetNode = NULL;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ;i<size;i++){
                Node* curNode = q.front();
                if(curNode->data == target) 
                    targetNode = curNode;
                q.pop();
                if(curNode->left)
                    {
                        q.push(curNode->left);
                        parentMapping[curNode->left]=curNode;
                    }
                if(curNode->right)
                    {
                        q.push(curNode->right);
                        parentMapping[curNode->right]=curNode;
                    }
            }
        }
        return targetNode;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==0)
            return 0;
        unordered_map<Node* , Node*> parentMapping;
        unordered_map<Node* , bool > visited;
        Node* targNode = mapParent(root,parentMapping,target);
        if(!targNode)  
            return -1;
        int burnTime = 0;
        queue<Node*> q;
        q.push(targNode);
        visited[targNode]=true;
        while(!q.empty()){
            int size = q.size();
            bool didBurn = false;
            for(int i=0;i<size;i++){
                Node* curNode = q.front();
                q.pop();
                if(curNode->left && !visited[curNode->left])
                    {
                        didBurn=true;
                        q.push(curNode->left);
                        visited[curNode->left]=true;
                    }
                if(curNode->right && !visited[curNode->right])
                    {
                        didBurn = true;
                        q.push(curNode->right);
                        visited[curNode->right]=true;
                    }
                if(parentMapping[curNode]!=NULL && !visited[parentMapping[curNode]])
                    {
                        didBurn = true;
                        q.push(parentMapping[curNode]);
                        visited[parentMapping[curNode]]=true;
                    }
            }
            if(didBurn)
                burnTime++ ;
        }
        return burnTime;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends