// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node * temp = head;
        Node * oneH = NULL;
        Node * twoH = NULL;
        Node * zeroH = NULL;
        Node * oneCur = NULL;
        Node * twoCur = NULL;
        Node * zeroCur = NULL;
        while(temp!=NULL){
            Node* toAdd = temp;
            int val = toAdd->data;
            if(val == 0){
                if(!zeroH)
                {
                    zeroH = temp;
                    zeroCur = zeroH;
                }
                else{
                    zeroCur->next=temp;
                    zeroCur=zeroCur->next;
                }
            }
            else if(val == 1){
                if(!oneH)
                {
                    oneH = temp;
                    oneCur = oneH;
                }
                else{
                    oneCur->next=temp;
                    oneCur=oneCur->next;
                }
            }
            else{
                if(!twoH)
                {
                    twoH = temp;
                    twoCur = twoH;
                }
                else{
                    twoCur->next=temp;
                    twoCur=twoCur->next;
                }
            }
            temp = temp->next;
        }
        if(zeroH){
            zeroCur->next=oneH;
            if(oneH){
                oneCur->next=twoH;
                if(twoH)
                    twoCur->next=NULL;
            }else{
                zeroCur->next=twoH;
                if(twoH)
                    twoCur->next=NULL;
            }
        return zeroH;
        }
        else if(oneH){
            oneCur->next=twoH;
            if(twoH){
                twoCur->next=NULL;
            }
            return oneH;
        }
        else if(twoH){

            twoCur->next=NULL;
            return twoH;        
        }
        else 
            return NULL;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends