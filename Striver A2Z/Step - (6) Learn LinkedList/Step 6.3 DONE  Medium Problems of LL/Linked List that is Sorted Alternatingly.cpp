// https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-that-is-sorted-alternatingly

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    }
    b->next = merge(a, b->next);
    return b;
}

/* Function to split a linked list into two halves */
void split(Node* head, Node** front, Node** back) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

/* Function to merge sort a linked list */
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) {
        return;
    }
    Node* front = NULL;
    Node* back = NULL;
    split(head, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *headRef = merge(front, back);
}

/* Function to sort a linked list */
void sort(Node **headRef) {
    mergeSort(headRef);
}


