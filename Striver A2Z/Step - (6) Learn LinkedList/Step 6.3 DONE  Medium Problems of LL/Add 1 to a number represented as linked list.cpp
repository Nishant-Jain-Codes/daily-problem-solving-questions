https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* revList(Node* head){
        if(head==NULL||head->next==NULL)
            return head;
        Node* tail = head->next;
        Node* newHead = revList(tail);
        tail->next=head;
        head->next=NULL;
        return newHead;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp = revList(head);
        Node* ansH = NULL;
        Node* ansNext = NULL;
        int carry = 1 ;
        while(temp!=NULL){
            int no = temp->data + carry;
            carry = no>=10 ? 1:0;
            no%=10;
            Node* addNode = new Node(no);
            if(!ansH){
                ansH = addNode;
                ansNext = ansH;
            }else {
                ansNext->next = addNode;
                ansNext = ansNext->next;
            }
            temp=temp->next;
        }
        if(carry){
            Node* addNode = new Node(carry);
            ansNext->next=addNode;
            ansNext = ansNext->next;
        }
        return revList(ansH);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends