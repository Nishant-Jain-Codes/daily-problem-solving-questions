// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-two-bst-s


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
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
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    // time ans space O(M+N)
    void inOrder(Node* root , vector<int>&output){
        if(!root)
            return ;
        inOrder(root->left,output);
        output.push_back(root->data);
        inOrder(root->right,output);
    }
    void merge(vector<int> arr1,vector<int> arr2, vector<int>& answer){
        int i=0,j=0;
        while(i<arr1.size()&&j<arr2.size()){
            if(arr1[i]<arr2[j])
            {
                answer.push_back(arr1[i++]);
            }
            else 
            {
                answer.push_back(arr2[j++]);    
            }
        }
        while(i<arr1.size()){
            answer.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            answer.push_back(arr2[j++]);
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> arr1;
       vector<int> arr2;
       inOrder(root1,arr1);
       inOrder(root2,arr2);
       int i=0;
       int j=0;
       vector<int> answer;
       merge(arr1,arr2,answer);
       return answer;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends

//space optimized solution
class Solution {
public:
    vector<int> merge(Node* root1, Node* root2) {
        vector<int> answer;
        stack<Node*> stk1, stk2;
        Node* curr1 = root1;
        Node* curr2 = root2;

        while (curr1 || curr2 || !stk1.empty() || !stk2.empty()) {
            // Traverse to the leftmost node of root1 and push all encountered nodes onto stk1
            while (curr1) {
                stk1.push(curr1);
                curr1 = curr1->left;
            }

            // Traverse to the leftmost node of root2 and push all encountered nodes onto stk2
            while (curr2) {
                stk2.push(curr2);
                curr2 = curr2->left;
            }

            // Get the top nodes from stk1 and stk2 if they are not empty
            Node* top1 = stk1.empty() ? NULL : stk1.top();
            Node* top2 = stk2.empty() ? NULL : stk2.top();

            // Compare the node values and merge
            if (top1 && top2) {
                if (top1->data < top2->data) {
                    answer.push_back(top1->data);
                    stk1.pop();
                    curr1 = top1->right;
                } else {
                    answer.push_back(top2->data);
                    stk2.pop();
                    curr2 = top2->right;
                }
            } else if (top1) {
                answer.push_back(top1->data);
                stk1.pop();
                curr1 = top1->right;
            } else if (top2) {
                answer.push_back(top2->data);
                stk2.pop();
                curr2 = top2->right;
            }
        }

        return answer;
    }
};
