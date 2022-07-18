/*
Problem Statement
Given the head node of the singly linked list, return a pointer pointing to the middle of the linked list.
If there are an odd number of elements, return the middle element if there are even elements return the one which is farther from the head node.
For example, let the linked list be 1->2->3->4->null

Since the number of elements in this linked list is 4 so we have 2 middle elements, i.e. 2 and 3, but we return 3 as it is farther from the head node, i.e. 1.
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next ‘2*T’ lines represent the ‘T’ test cases.

The first and only line of each test case contains integers denoting the nodes of the linked list. Each line is guaranteed to have -1 at the end to signify the end of the linked list.
Output Format :
For each test case, return a pointer pointing to the node which is at the middle of the linked list. If no midpoint exists, return a null pointer.
Note :
1.You do not need to print anything, it has already been taken care of. Just implement the given function.

2.For a linked list of size 1, the head node is the midpoint.

3.If no midpoint exists, return a null pointer.
Constraints :
1 <= T <= 50
1 <= N <= 4*10^4
-10^9 <= data <= 10^9 
data ≠ -1

Where 'N' is the number of nodes and 'data' is the value of nodes.

Time Limit: 1 sec
Sample Input 1 :
2
1 2 3 4 5 -1
4 0 32 5 48 6 -1
Sample Output 1 :
3
5
Explanation Of Sample Input 1 :
For the first test case:

The linked List is 1->2->3->4->5->NULL
We can clearly see that there are 5 elements in the linked list and the middle element is 3 hence we return a pointer poiniting to the middle element i.e 3.

For the second test case:

The linked List is : 4->0->32->5->48->6->NULL

We have 6 elements in the linked list. we will have 2 middle elements i.e 32 and 5. Since it is specified to return the element farther from the root node, we return 5.
Sample Input 2 :
2
2 69 7 -1
1 4 5 8 9 6 3 -1
Sample Output 2 :
69
8

*/

// solution 
#include <bits/stdc++.h> 
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

Node *findMiddle(Node *head) {
   Node *slow = head;
    Node *fast = head;
    while(head!=NULL)
    {
        if(fast == NULL || fast  ->next == NULL)
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
