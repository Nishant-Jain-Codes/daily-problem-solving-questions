/*

Node at a given index in linked list
BasicAccuracy: 46.18%Submissions: 65136Points: 1
Given a singly linked list with N nodes and a number X. The task is to find the node at the given index (X)(1 based index) of linked list. 

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains space seperated two integers, length of linked list and X.

Output:
For each testcase, there will be single line of output containing data at Xth node.

User Task:
The task is to complete the function GetNth() which takes head reference and index as arguments and should return the data at Xth position in the linked list.

Constraints:
1 <= T <= 30
1 <= N <= 100
K <= N
1 <= value <= 103

Example:
Input:
2
6 5
1 2 3 4 657 76
10 2
8 7 10 8 6 1 20 91 21 2

Output:
657
7

Explanation:
Testcase 1: Element at 5th index in the linked list is 657 (1-based indexing).

*/

// solution 

struct node* getNth2(struct node* head, int index)
{
    if(head==NULL||index==0)
        return head;
    if(index==1)
        return head;
    else
        return getNth2(head->next,index-1);
}
int GetNth(struct node* head, int index){
  // Code here
  if(head==NULL||index==0)
    return -1;
  return getNth2(head,index)->data;
}
