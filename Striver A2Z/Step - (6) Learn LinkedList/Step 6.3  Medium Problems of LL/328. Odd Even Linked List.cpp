// https://leetcode.com/problems/odd-even-linked-list/submissions/900348710/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * temp = head;
        ListNode * oddH = NULL;
        ListNode * evenH = NULL;
        ListNode * oddCur = NULL;
        ListNode * evenCur = NULL;
        bool isOdd = true;
        while(temp!=NULL){
            ListNode* toAdd = temp;
            if(isOdd){
                if(oddH==NULL){
                    oddH=toAdd;
                    oddCur=oddH;
                }else{
                    oddCur->next=toAdd;
                    oddCur=oddCur->next;
                }
                isOdd  = false;
            }else{
                if(evenH==NULL){
                    evenH=toAdd;
                    evenCur=evenH;
                }else{
                    evenCur->next=toAdd;
                    evenCur=evenCur->next;
                }
                isOdd = true;
            }
            temp=temp->next;
        };
        if(evenH)
            evenCur->next=NULL;
        if(oddH)
            {
                oddCur->next=evenH;
                return oddH;
            }
        
        return evenH;
    }
};