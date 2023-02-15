// https://leetcode.com/problems/linked-list-cycle-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//using O(N) space
   /* ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> map;
        while(head!=NULL){
            if(map.count(head)>0)
                return head;
            map[head]=true;
            head=head->next;
        }
        return NULL;
    }
    */
    //using O(1) space (logic:--)
        //L1 be distance from start to loopentry
        //l2 be distance from loopentry to slow fast collision point 
        //nC be n(no of turns) C(length of loop) (nC) is no of extra steps taken by fast pointer before colliding with slow
        //L1 = nC-L2
     ListNode *detectCycle(ListNode *head){
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                {
                    while(entry!=slow){
                        entry=entry->next;
                        slow = slow->next;
                    }
                    return entry;
                }
        }
        return NULL;
        
        
     }
};