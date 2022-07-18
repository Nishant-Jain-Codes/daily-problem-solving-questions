/*
Problem Statement
Given a singly linked list of integers. Your task is to return the head of the reversed linked list.
For Example:
The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
Follow Up :
Can you solve this problem in O(N) time and O(1) space complexity?
Input Format :
The first line of input contains an integer 'T' representing the number of test cases or queries to be processed. Then the test case follows.

The only line of each test case contains the elements of the singly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.
Output Format :
For each test case, print the given linked list in reverse order in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
0 <= L <= 10^5
1 <= data <= 10^9 and data != -1

Time Limit: 1 sec
Sample Input 1 :
1
1 2 3 4 5 6 -1
Sample Output 1 :
6 5 4 3 2 1 -1
Explanation For Sample Input 1 :
For the first test case,  After changing the next pointer of each node to the previous node, The given linked list is reversed.
Sample Input 2 :
1
10 21 3 2 4 -1
Sample Output 2 :
4 2 3 21 10 -1
*/
// soulution 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
     LinkedListNode<int> *tail = head->next;
    LinkedListNode<int> *temp = reverseLinkedList(head->next);
    tail->next=head;
    head->next=NULL;
    
    
    return temp;
}
