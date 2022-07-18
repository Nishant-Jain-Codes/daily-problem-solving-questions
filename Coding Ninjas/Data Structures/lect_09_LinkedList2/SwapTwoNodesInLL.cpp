/*

Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 

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
/*
Node*swapNodes(Node *Mhead, int si, int ei)
{
    Node *head = Mhead;
	if(head==NULL || head ->next ==NULL ||si==ei)
    {
        return head;
    }
    Node *p1=NULL;
    Node *p2=NULL;
    Node *c1=NULL;
    Node *c2=NULL;
    int k =0 ;
    while(head!=NULL)
    {
        if(k==si-1)
        {
            p1=head
        }
        else if(k==si)
        {
            c1=head;
        }
        else if(k==ei-1)
        {
            p2=head;
        }
        else if(k==ei)
        {
            c2=head;
        }
        head=head->next;
        k++;
    }
    p1->next=c2;
    p2->next=c1;
    c1->next=c2->next;
    c2->next=p2;
    if(si==0)
    {
        return p2;
    }
    else if(ei==0)
    {
        return p1
    }
    
    
}*/
Node*swapNodes(Node *Mhead, int s, int b)
{	
    Node *head = Mhead;
    if(head==NULL || head ->next ==NULL ||s==b)
    {
        return Mhead;
    }
    
    //finds bigger of (s,b);
    if(s>b)
    {
        int temp=s;
        s=b;
        b=temp;
    }
    
    if((s==0)&&(b-s==1))
    {
        Node *temp = head->next;
        head->next=temp->next;
        temp->next=head;
        return temp;
    }
    else if((s==0)&&(b-s!=1))
    {
        Node *c1 =head;
        Node *n = c1->next;
        Node *c2=NULL;
        Node *p =NULL;
        
        for(int i =0;i<=b;i++)
        {	
            if(i==b-1)
            {
                p=head;
            }
            else if(i==b)
            {
                c2=head;
            }
            
            head=head->next;
        }
        c1->next = c2->next;
        c2->next = n;
        p->next=c1;
        return c2;
        
    }
    else if((s!=0)&&(b-s==1))
    {
        Node *pre = NULL;
        Node *cur = NULL;
        Node *fut = NULL;
    	for(int i =0;i<=b;i++)
        {
            if(i==b-2)
            {
                pre = head;
            }
            else if(i==b-1)
            {
                cur = head;
            }
            else if(i==b)
            {
                fut = head;
            }
            
            head=head->next;
        }
		pre ->next = cur ->next;
        cur -> next = fut ->next ;
        fut ->next = cur;
        return Mhead;
    }
    else
    {
        Node *c1 =NULL;
        Node *p1 =NULL;
        Node *c2 =NULL;
        Node *p2 =NULL;
    	for(int i =0;i<=b;i++)
        {
            if(i==s-1)
            {
                p1=head;
            }
            else if(i==s)
            {
                c1=head;
            }
            else if(i==b-1)
            {
                p2=head;
            }
            else if(i==b)
            {
				c2=head;                
            }
           
            head=head->next;
            
        }
        Node *temp = c1->next;
        p1->next = c2;
        p2->next = c1;
        c1->next = c2->next;
        c2->next = temp;
        return Mhead;
    }
}
