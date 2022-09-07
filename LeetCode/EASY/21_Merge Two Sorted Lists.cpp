/*
https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan&id=level-1

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/
// solution

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2==NULL)
            return NULL;
        else if(list1==NULL)
            return list2;
        else if (list2 ==NULL)
            return list1;
        
        ListNode* head=NULL;
        if(list1->val<list2->val)
        {
                head=list1;
                list1=list1->next;
                head->next=NULL;
        }
        else
        {
                head=list2;
                list2=list2->next;
                head->next=NULL;
            
        }
        ListNode* thead=head;
        while(list1!=NULL&&list2!=NULL)
        {
            if(list1->val<list2->val)
        {
                thead->next=list1;
                thead=thead->next;
                list1=list1->next;
                thead->next=NULL;
        }
        else
        {
                thead->next=list2;
                thead=thead->next;
                list2=list2->next;
                thead->next=NULL;
            
        }
        }
            
        
        if(list1==NULL&&list2!=NULL)
                {thead->next=list2;}
        else if(list1!=NULL&&list2==NULL)
                {thead->next=list1;}
            
            return head;
        
        
    }
