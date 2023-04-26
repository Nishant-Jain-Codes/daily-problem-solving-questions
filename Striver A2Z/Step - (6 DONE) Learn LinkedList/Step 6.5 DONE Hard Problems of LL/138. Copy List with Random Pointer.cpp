https://leetcode.com/problems/copy-list-with-random-pointer/description/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        
        Node* curr = head;
        while (curr != NULL) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

    
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

    
        Node* newHead = head->next;
        curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next != NULL) {
                temp->next = temp->next->next;
            }
            curr = curr->next;
        }

        return newHead;
    }
};
