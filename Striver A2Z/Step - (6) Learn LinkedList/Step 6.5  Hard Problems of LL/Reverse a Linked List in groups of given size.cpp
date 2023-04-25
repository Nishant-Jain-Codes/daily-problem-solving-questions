// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { if(!head || !head->next || k<=1)
            return head;
        struct node* dummy = new node(-1);
        dummy->next=head;
        struct node *cur = dummy,*nex=dummy,*pre=dummy,*temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=0;i<k-1;i++){
                cur->next= nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
                if(!nex)
                    break;
            }
            pre=cur;
            count-=k;
        }
        // handle left-out nodes at the end of the list
        if(count > 0) {
            cur=pre->next;
            nex=cur->next;
            for(int i=0;i<count-1;i++){
                cur->next= nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
        }
        return dummy->next;
    
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends