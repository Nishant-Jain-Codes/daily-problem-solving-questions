/*
Problem Statement
You are given a Singly Linked List of integers. You have to find if the given linked list is circular or not.
A circular linked list is a sequence of elements in which every element has a link to its next element in the sequence and the last element has a link to the first element. This means that circular linked list is similar to the single linked list except that the last node points to the first node in the list.

Input Format
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

The first line of each test case contains the elements of the circular linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

The second line contains a boolean value ‘val’, if ‘val’ is 1 then the given list is circular.
Output Format
For each test case, print “True” if the given linked list is circular, else print “False”.

Print the output of each test case in a separate line.
Note
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 10
1 <= N <= 5 * 10^4
-10^9 <= data <= 10^9 and data != -1
0 <= val <= 1

Where 'N' is the number of nodes in the linked list, ‘data’ represents the value of the nodes of the list.

Time Limit: 1 sec
Sample Input 1
3
1 2 3 4 -1
1
8 9 8 -1
0
4 -1
1
Sample Output 1
True
False
True
Explanation For Sample Input 1
In the 1st test case, the given list is circular.
In the 2nd test case, the given list is not circular.
In the 3rd test case,  the given list is circular.
Sample Input 2
2
3 2 1 -1
1
1 1 1 -1
0
Sample Output 2
True
False
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

bool circularLL(Node* head)
{
    // Write your code here
    Node *temp = head;
    while(temp->next!=head&&temp->next!=NULL)
    {
        temp = temp->next;
    }
    return temp->next == head ;
}
