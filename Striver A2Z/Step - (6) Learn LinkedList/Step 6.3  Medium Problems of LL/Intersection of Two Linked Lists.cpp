//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        unordered_map<int,int> map;
        Node* temp = head1;
        while(temp!=NULL){
            map[temp->data]++;
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL){
            map[temp->data]++;
            temp=temp->next;
        }
        temp = head1;
        Node * ans = NULL;
        Node* ansNex = NULL;
        while(temp!=NULL){
            if(map[temp->data]>1){
                Node * addnode = new Node(temp->data);
                if(!ans)
                {
                    ans=addnode;
                    ansNex=ans;
                }else{
                    ansNex->next=addnode;
                    ansNex=ansNex->next;
                    
                }
                ansNex->next=NULL;
            }
            temp = temp->next;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends