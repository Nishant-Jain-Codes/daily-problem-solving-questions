/*
https://www.codechef.com/LP2TO301/problems/MANYSUMS

You are given a range of integers \{L, L+1, \ldots, R\}{L,L+1,…,R}. An integer XX is said to be reachable if it can be represented as a sum of two not necessarily distinct integers in this range. Find the number of distinct reachable integers.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains two space-separated integers LL and RR.
Output
For each test case, print a single line containing one integer — the number of reachable integers.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \leq L \leq R \leq 10^61≤L≤R≤10 
6
 
Sample 1:
Input
Output
2
2 2
2 3
1
3
Explanation:
Example case 1: The only reachable integer is 2 + 2 = 42+2=4.

Example case 2: 44, 55 and 66 are reachable, since 2+2=42+2=4, 2+3=52+3=5 and 3+3=63+3=6.
*/


// solution 

void solution()
{
  int l,r;cin>>l>>r;
  int ans=(2*r)-(2*l)+1;
  co(ans);
}
