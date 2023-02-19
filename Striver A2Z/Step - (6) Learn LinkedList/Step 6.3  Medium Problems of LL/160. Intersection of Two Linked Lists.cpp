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
    //O(n) memory
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool> map;
        ListNode* temp = headA;
        while(temp!=NULL){
            map[temp]=true;
            temp=temp->next;
        }
        temp = headB;
        while(temp!=NULL){
            if(map.find(temp)!=map.end())
                return temp;  
            temp=temp->next;
        }
        return NULL;
    }
};