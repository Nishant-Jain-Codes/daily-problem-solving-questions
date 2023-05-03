// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=nodes-at-given-distance-in-binary-tree


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
Node* mapParent(Node* root , unordered_map<Node* , Node*> & parentMapping , int target){
        queue<Node*> q;
        q.push(root);
        parentMapping[root]=NULL;
        Node* targetNode = NULL;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ;i<size;i++){
                Node* curTreeNode = q.front();
                if(curTreeNode->data == target)
                    targetNode = curTreeNode;
                q.pop();
                if(curTreeNode->left)
                    {
                        q.push(curTreeNode->left);
                        parentMapping[curTreeNode->left]=curTreeNode;
                    }
                if(curTreeNode->right)
                    {
                        q.push(curTreeNode->right);
                        parentMapping[curTreeNode->right]=curTreeNode;
                    }
            }
        }
        return targetNode;
    
    }
    vector <int> KDistanceNodes(Node* root, int t, int k)
    {
        // return the sorted vector of all nodes at k dist
        if(!root)
            return {};
        vector<int> answer;
        queue<pair<Node*,int>> q;
        unordered_map<Node*,bool> visited;
        unordered_map<Node*,Node*> parent;
        Node* target = mapParent(root,parent,t);
        if(!target)
            return {};
        q.push({target,0});
        visited[target]=true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* curNode = q.front().first;
                int curDist = q.front().second;
                q.pop();
                if(curDist==k)
                    answer.push_back(curNode->data);
                if(curNode->left && !visited[curNode->left]){
                    visited[curNode->left]=true;
                    q.push({curNode->left,curDist+1});
                }
                if(curNode->right && !visited[curNode->right]){
                    visited[curNode->right]=true;
                    q.push({curNode->right,curDist+1});
                }
                if(parent[curNode] && !visited[parent[curNode]]){
                    visited[parent[curNode]]=true;
                    q.push({parent[curNode],curDist+1});
                }
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends