// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-if-linked-list-is-pallindrome

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
     int reverseInt(int n){
        int rev=0;
   while(n>0){

     int rem=n%10;
     rev = rev*10 + rem;
     n /= 10;
   }    return rev;

    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        int frontHalf = 0;
        Node * slow=head;
        Node * fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* mid = slow;
        bool odd = true;
        if(fast->next!=NULL)
            odd = false;
        int front=0,rear=0;
        Node * temp = head;
        while(temp!=mid){
            front = front*10 + temp->data;
            temp=temp->next;
        }
        if(!odd){
            front= front*10 + mid->data;
        }
        temp = mid->next;
        while(temp!=NULL){
            rear = rear*10 + temp->data;
            temp=temp->next;
        }
        
        return front == reverseInt(rear);
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends