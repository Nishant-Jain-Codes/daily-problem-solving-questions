// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
        return NULL;
    if(head->next==NULL)
        {
            delete head;
            return NULL;
        }
    ListNode *fast = head;
    ListNode *slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
            
    }
    if(fast->next!=NULL)
        slow=slow->next;
    ListNode* temp=head;
    while(temp->next!=slow)
        temp=temp->next;
    temp->next=temp->next->next;
    slow->next=NULL;
    delete slow;
    return head;
    }
};