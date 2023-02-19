// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-two-numbers-represented-by-linked-lists

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* revList( struct Node* head){
        if(head==NULL || head->next==NULL)
            return head;
        struct Node* tail = head->next;
        struct Node* newHead = revList(tail);
        tail->next=head;
        head->next=NULL;
        return newHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* l1 = revList(first);
        struct Node* l2 = revList(second);
        struct Node* ansH = NULL;
        struct Node* ansNext = NULL;
        int carry =0;
        while(l1!=NULL && l2!=NULL){
            int no = l1->data + l2->data +carry;
            carry = no>=10? 1:0;
            no%=10;
            struct Node* addNode = new Node(no);
            if(!ansH){
                ansH=addNode;
                ansNext = ansH;
            }else{
                ansNext->next = addNode;
                ansNext = ansNext->next; 
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int no = l1->data +carry;
            carry = no>=10? 1:0;
            no%=10;
            struct Node* addNode = new Node(no);
            if(!ansH){
                ansH=addNode;
                ansNext = ansH;
            }else{
                ansNext->next = addNode;
                ansNext = ansNext->next; 
            }
            l1=l1->next;
        }
        while(l2!=NULL){
            int no = l2->data +carry;
            carry = no>=10? 1:0;
            no%=10;
            struct Node* addNode = new Node(no);
            if(!ansH){
                ansH=addNode;
                ansNext = ansH;
            }else{
                ansNext->next = addNode;
                ansNext = ansNext->next; 
            }
            l2=l2->next;
        }
        if(carry!=0){
             struct Node* addNode = new Node(carry);
             ansNext->next = addNode;
                ansNext = ansNext->next; 
        }
        ansH = revList(ansH);
        return ansH;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends