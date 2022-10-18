/*
https://www.codechef.com/LP2TO301/problems/ALTER?tab=statement


Alice and Bob are two friends. Initially, the skill levels of them are zero. They work on alternative days, i.e one of Alice and Bob works on the odd-numbered days(1, 3, 5, \dots)(1,3,5,…) and the other works on the even-numbered days (2, 4, 6, \dots)(2,4,6,…). The skill levels of Alice and Bob increase by A, BA,B respectively on the days they work.

Determine if it is possible that the skill levels of Alice and Bob become exactly P, QP,Q respectively on some day.

Input Format
The first line contains an integer TT, denoting the number of test cases. The TT test cases then follow:
The first and only line of each test case contains four space-separated integers A, B, P, QA,B,P,Q.
Output Format
For each test case, print YES if it is possible that the skill levels of Alice and Bob become exactly P, QP,Q on some day, otherwise print NO.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1 \leq T \leq 10^31≤T≤10 
3
 
1 \leq A, B, P, Q \leq 10^91≤A,B,P,Q≤10 
9
 
Subtasks
Subtask 1 (100 points): Original constraints
Sample 1:
Input
Output
4
1 2 1 2
1 2 3 2
4 3 4 6
3 5 9 25
YES
NO
YES
NO
Explanation:
Test Case 11: Alice works on the first day and gains skill level 11. Bob works on the second day and gains skill level 22.

Test Case 22: There is no possible way that the skill levels of Alice and Bob become 33 and 22 respectively.

Test Case 33: Bob works on the first and third day and Alice works on the second day. Hence after the third day, the skill levels of Alice and Bob become 1\cdot4 = 41⋅4=4 and 2 \cdot 3 = 62⋅3=6 respectively.
*/

// solution 

void solution()
{
    int d1;cin>>d1;
    int d2;cin>>d2;
    int An;cin>>An;
    int Bn;cin>>Bn;
    
    int n1 = ((An)/d1) +1;
    int n2 = ((Bn)/d2) +1;
    
    if(abs(n1-n2)<=1&&An%d1==0&&Bn%d2==0)
        {co(yes);}
    else 
        {
            co(no);
        }
  
  
}
