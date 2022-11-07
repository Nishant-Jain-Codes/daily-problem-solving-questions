/*

Code: Merge Sort
Send Feedback
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 

*/

// solution 

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *midPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(head!=NULL)
    {
        if(fast->next == NULL || fast -> next ->next == NULL)
        {
            return slow ;
        }
        else
        {
			fast = fast ->next->next;
            slow = slow ->next ;
            
        }
    }
}
//*****************************************************************/

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *ft = NULL ;
    Node *fh = NULL ;
   if(head1!=NULL && head2!= NULL)
   {
       if(head1->data<head2->data)
    {
        fh = head1;
        ft= head1;
        head1=head1->next;
    }
    else
    {
        fh = head2;
        ft= head2;
        head2=head2->next;
    }
    while(head1 != NULL && head2!= NULL)
    {
        if(head1->data<head2->data)
        {
            ft->next = head1;
            ft=head1;
            head1=head1->next;
        }
        else
        {
            ft->next  = head2;
            ft = head2;
            head2=head2->next;
        }
    }
       if(head1==NULL)
       {
		ft->next=head2;
       }
       if(head2==NULL)
       {
           ft->next=head1;
       }
       return fh;
   } else if (head1==NULL&&head2!=NULL)
       {
           return head2;
       }
       else if(head1!=NULL && head2 == NULL)
       {
           return head1;
       }
       else
       {
           return NULL;
       }

}

Node *mergeSort(Node *head)
{
	if(head==NULL || head -> next == NULL)
    {
        return head;
    }
    Node *mid = midPoint(head);
    Node *sh = mergeSort(mid->next);
    mid->next = NULL;
    Node *fh = mergeSort(head);
    Node *ans = mergeTwoSortedLinkedLists(fh,sh);
    return ans;
    
}
