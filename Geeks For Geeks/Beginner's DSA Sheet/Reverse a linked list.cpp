/*
Reverse a linked list
EasyAccuracy: 48.93%Submissions: 100k+Points: 2
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.  

Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104
*/

// solution 

struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL||head->next==NULL)
            return head;
        struct Node* tail=head->next;
        struct Node* newhead = reverseList(head->next);
        tail->next=head;
        head->next=NULL;
        return newhead;
    }
