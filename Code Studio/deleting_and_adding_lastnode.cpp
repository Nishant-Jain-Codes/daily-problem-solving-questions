/*
Problem Statement
You are provided with a singly linked list, all you have to do is to delete the last node of the linked list and add it to the front of the linked list.
Example:

Please note that the linked list will only contain numeric values.
Input Format:
The first line contains a single integer ‘T’ representing the number of test cases. 

The first line of each test case will contain the elements of the linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.
Output Format:
For each test case, return the new head node of the linked list after adding the last node to its front.

Print the output of each test case in a separate line.
Note:
You don’t need to print anything, It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
0 <= N <= 10000
-10^4 <= LIST[i] <= 10^4

Where 'N' is the total number of nodes in the given linked list. ‘LIST[i]’ represents the node value of the node ‘i’.

Time limit: 1 sec
Sample Input 1:
2
2 5 3 11 1 -1
2 -1
Sample Output 1:
1 2 5 3 11 -1
2 -1
Explanation Of Sample Output 1:
In test case 1, the new linked list after doing delete and add operations to the last node: 1 2 5 3 11 -1.

In test case 2, the linked list has only one node and so, the last node is itself at the front.
Sample Input 2:
2
4 3 -1
1 1 1 1 -1
Sample Output 2:
3 4 -1
1 1 1 1 -1
Explanation For Sample Output 2:
In test case 1, the new linked list after doing delete and add operations to the last node: 3 4 -1.

In test case 2, the new linked list after swapping first and last nodes: 1 1 1 1 -1.
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

Node *delAddLastNode(Node *head){
	// Write your code here.
    Node *temp = head;
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}
