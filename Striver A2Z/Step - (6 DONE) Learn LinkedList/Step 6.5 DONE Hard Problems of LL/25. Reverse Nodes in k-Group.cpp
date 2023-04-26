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
    int countNodes(ListNode* head){
        if(head==NULL)
            return 0;
        return 1+countNodes(head->next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<=1)
            return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur=dummy,*pre=dummy,*nex=dummy;
        dummy->next=head;
        int count = countNodes(head);
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=0;i<k-1;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex = cur->next;
            }
            pre = cur;
            count-=k;
        }
        return dummy->next;
    }
};