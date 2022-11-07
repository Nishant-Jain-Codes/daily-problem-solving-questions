/*

Next Number
Send Feedback
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 

*/

// solution 

/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
Node *reverseLinkedListRec(Node *head)
{
    if(head == NULL || head->next == NULL )
    {
        return head;
    }
    Node *newhead = reverseLinkedListRec(head->next);
    Node *tail = head->next ;
    tail->next=head;
    head->next=NULL;
    
    return newhead;
}
Node* NextLargeNumber(Node *head) {
    head = reverseLinkedListRec(head);
    Node *temp =head;
    int carry = 1;
    while(temp!=NULL)
    {	
        temp->data =temp->data  + carry;
        if(temp->data==10)
        {
            temp->data = 0;
            carry=1;
        }
        else
        {
            carry=0;
        }
     if(temp->next==NULL&&carry == 1)
     {
         Node *newnode =new Node(1);
         temp->next =newnode;
         temp->next->data = 0;
     }
         
        temp=temp->next;
    }
    head = reverseLinkedListRec(head);
    return head;
}


