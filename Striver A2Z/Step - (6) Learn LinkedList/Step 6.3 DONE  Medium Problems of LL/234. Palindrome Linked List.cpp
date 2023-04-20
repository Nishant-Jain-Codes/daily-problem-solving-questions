https://leetcode.com/problems/palindrome-linked-list/description/

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
 
    ListNode * midOfList(ListNode * head){
        ListNode * slow=head;
        ListNode * fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode * reverseList(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode * tail = head->next;
        ListNode * newHead = reverseList(head->next);
        tail->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * mid = midOfList(head);
        ListNode * revList = reverseList(mid->next);
        ListNode* left = head;
        ListNode* right = revList;
        while(right!=NULL && left!=NULL){
            if(right->val!=left->val)
                return false;
            right = right->next;
            left = left->next;
        }
        return true;
    }
};