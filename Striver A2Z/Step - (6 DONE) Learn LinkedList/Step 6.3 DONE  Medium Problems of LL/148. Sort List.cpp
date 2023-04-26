// https://leetcode.com/problems/sort-list/description/

/**
 * Definition for singly-linked List.
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
    ListNode* merge(ListNode* left,ListNode*right){
        ListNode* newHead = NULL;
        ListNode* newNext = NULL;
        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
                if(!newHead){
                    newHead = left;
                    left=left->next;
                    newNext = newHead;
                    newNext->next=NULL;
                }else{
                    newNext->next = left;
                    left=left->next;
                    newNext=newNext->next;
                    newNext->next = NULL;
                }
            }
            else{
                if(!newHead){
                    newHead = right;
                    right=right->next;
                    newNext = newHead;
                    newNext->next=NULL;
                }else{
                    newNext->next = right;
                    right=right->next;
                    newNext=newNext->next;
                    newNext->next = NULL;
                }
            }
        }
        if(right){
            if(!newHead)
                return right;
            else 
                newNext->next = right;
        }
        if(left){
            if(!newHead)
                return left;
            else 
                newNext->next = left;
        }
        return newHead;
    }
    ListNode* midOfList(ListNode* head){
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next !=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* mid = midOfList(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next=NULL;
        ListNode* leftSorted = sortList(left);
        ListNode* rightSorted = sortList(right);
        return merge(leftSorted,rightSorted);
    }
};