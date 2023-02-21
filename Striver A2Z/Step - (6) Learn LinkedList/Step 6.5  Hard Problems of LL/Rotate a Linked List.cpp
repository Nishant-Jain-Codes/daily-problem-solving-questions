// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotate-a-linked-list


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    int sizeOfList(Node* head){
        Node * temp = head;
        int cnt = 0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    Node* rotate(Node* head, int k)
    {
        // Your code here
        int size = sizeOfList(head);
        k = k % size;
        Node* newHead = head;
        while(k--){
            newHead=newHead->next;
        }
        Node* tempT = newHead;
        while(tempT->next!=NULL)
            tempT=tempT->next;
        tempT->next=head;
        Node* t = head;
        while(t->next != newHead)
            t=t->next;
        t->next=NULL;
    
        return newHead;
        
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends