/*
https://www.codechef.com/START55D/problems/BALLBOX


Problem
You have NN balls and KK boxes. You want to divide the NN balls into KK boxes such that:

Each box contains \ge 1≥1 balls.
No two boxes contain the same number of balls.
Determine if it is possible to do so.

Input Format
The first line contains a single integer TT — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space-separated integers NN and KK — the number of balls and the number of boxes respectively.
Output Format
For each test case, output YES if it is possible to divide the NN balls into KK boxes such that the conditions are satisfied. Otherwise, output NO.

You may print each character of YES and NO in uppercase or lowercase (for example, yes, yEs, Yes will be considered identical).

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \le N \le 10^91≤N≤10 
9
 
1 \le K \le 10^41≤K≤10 
4
 
Sample 1:
Input
Output
4
3 4
30 3
2 2
1 1
NO
YES
NO
YES
Explanation:
Test Case 1: It is not possible to divide the 33 balls into 44 boxes such that each box contains \ge 1≥1 balls.

Test Case 2: One way to divide the 3030 balls into 33 boxes is the following: [5, 9, 16][5,9,16].

Test Case 3: It is not possible to divide the 22 balls into 22 boxes such that no two boxes contain the same number of balls.

Test Case 4: We can divide 11 ball into 11 box.
*/

// solution 

void solution()
{
  int n;cin>>n;
  int k;cin>>k;
    int n1=(k*(k+1))/2;
  if((n>=n1)&&(n>=k))
    {co(yes);}
    else
    {co(no);}
  
}
