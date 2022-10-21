/*
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/
#include <bits/stdc++.h> 
using namespace std; 

struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode * temp = node->next;
        node->next=node->next->next;
        temp->next=NULL;
        delete temp;
    }
};