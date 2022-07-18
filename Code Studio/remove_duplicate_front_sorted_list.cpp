/*

Problem Statement
You want to play with your friend, but your friend has pending homework, help him complete that.
You are given a ‘Head’ of a sorted linked list. You can remove some values from the linked list. In the end, you must return a sorted linked list that contains no adjacent values that are equal.
For Example :
If the given linked list is: 1 -> 2 -> 2 -> 3

Then we will delete the duplicate value ‘2’ present in the linked list, and finally return the following list:
1 -> 2 -> 3
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first and only line of each test case contains the elements of the first linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.
Output Format :
For each test case, print the final linked list. The elements of the linked list must be separated by a single space and terminated by -1.

Output for each test case will be printed in a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 ≤ T ≤ 10      
0 ≤ Length ≤ 10^5
1 ≤ data ≤ 10^6 and data != -1

Time limit: 1 sec
Sample Input 1 :
2
1 2 2 3 -1
1 2 3 4 -1
Sample Output 1 :
1 2 3 -1
1 2 3 4 -1
Explanation For Sample Input 1 :
For test case 1, we will return 1 -> 2 -> 3 -> NULL, because : 
We will delete the duplicate value ‘2’ present in the linked list, and finally return the following list:
1 -> 2 -> 3


For test case 2, we will return 1 -> 2 -> 3 -> 4 -> NULL, because the input list contains no duplicates, so we will return it as it is.
Sample Input 2 :
2
1 -1
2 5 5 5 5 -1 
Sample Output 2 :
1 -1
2 5 -1


*/


// solution 

/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node *temp = head;
    while(temp!=NULL&&temp->next!=NULL)
    {    
        
            while(temp!=NULL&&temp->next!=NULL&&((temp->data)==(temp->next)->data))
            {
                Node *del = temp->next;
                temp->next=del->next;
                del->next=NULL;
                delete del;
            }
        if(temp->next!=NULL)
           temp=temp->next;
        else
            break;
    }
    return head;
}
