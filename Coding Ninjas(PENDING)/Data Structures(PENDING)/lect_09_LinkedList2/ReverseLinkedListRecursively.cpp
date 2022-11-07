/*



*/

// solution 
//method 1
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
// method 2
pair *reverseLinkedListRec_2(Node *head)
{
    if(head == NULL || head->next == NULL )
    {
        pair ans;
        pair.head = head;
        pair.tail = head;
        return ans;
    }
    pair newhead = reverseLinkedListRec_2(head->next);
    newhead.tail->next=head;
    head->next=NULL;
    pair ans;
    ans.head=newhead.head;
    ans.tail=head;
    return ans;
}
// method 3
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head == NULL || head->next == NULL )
    {
        return head;
    }
    Node *newhead = reverseLinkedListRec(head->next);
    Node *temp = newhead ;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head ;
    temp ->next->next = NULL ;
    return newhead;
}
