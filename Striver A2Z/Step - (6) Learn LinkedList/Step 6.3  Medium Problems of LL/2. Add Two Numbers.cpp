// https://leetcode.com/problems/add-two-numbers/description/

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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansH = NULL;
        ListNode* ansNext = NULL;
        int carry =0;
        while(l1!=NULL && l2!=NULL){
            int no = l1->val + l2->val +carry;
            carry = no>=10? 1:0;
            no%=10;
            ListNode* addNode = new ListNode(no);
            if(!ansH){
                ansH=addNode;
                ansNext = ansH;
            }else{
                ansNext->next = addNode;
                ansNext = ansNext->next; 
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int no = l1->val +carry;
            carry = no>=10? 1:0;
            no%=10;
            ListNode* addNode = new ListNode(no);
            if(!ansH){
                ansH=addNode;
                ansNext = ansH;
            }else{
                ansNext->next = addNode;
                ansNext = ansNext->next; 
            }
            l1=l1->next;
        }
        while(l2!=NULL){
            int no = l2->val +carry;
            carry = no>=10? 1:0;
            no%=10;
            ListNode* addNode = new ListNode(no);
            if(!ansH){
                ansH=addNode;
                ansNext = ansH;
            }else{
                ansNext->next = addNode;
                ansNext = ansNext->next; 
            }
            l2=l2->next;
        }
        if(carry!=0){
             ListNode* addNode = new ListNode(carry);
             ansNext->next = addNode;
                ansNext = ansNext->next; 
        }
        return ansH;
    }
};