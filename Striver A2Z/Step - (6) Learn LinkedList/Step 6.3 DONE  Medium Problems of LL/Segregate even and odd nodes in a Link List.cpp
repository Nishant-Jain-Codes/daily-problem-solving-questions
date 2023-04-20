// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=segregate-even-and-odd-nodes-in-a-linked-list

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
        cout << node->data <<" "; 
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
class Solution{
public:
     Node* divide(int N, Node *head){
        // code here
        Node * temp = head;
        Node * oddH = NULL;
        Node * evenH = NULL;
        Node * oddCur = NULL;
        Node * evenCur = NULL;
        while(temp!=NULL){
            Node* toAdd = temp;
            bool isOdd = (toAdd->data % 2) != 0;
            if(isOdd){
                if(oddH==NULL){
                    oddH=toAdd;
                    oddCur=oddH;
                }else{
                    oddCur->next=toAdd;
                    oddCur=oddCur->next;
                }
               
            }else{
                if(evenH==NULL){
                    evenH=toAdd;
                    evenCur=evenH;
                }else{
                    evenCur->next=toAdd;
                    evenCur=evenCur->next;
                }
            }
            temp=temp->next;
        };
        if(oddH){
            oddCur->next=NULL;    
        }
        
        if(evenH)
        {
            evenCur->next=oddH;
            return evenH;
            
        }
        return oddH;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends