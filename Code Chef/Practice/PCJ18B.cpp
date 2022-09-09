/*
https://www.codechef.com/submit/PCJ18B?tab=statement


Problem
Chef has recently been playing a lot of chess in preparation for the ICCT (International Chef Chess Tournament).

Since putting in long hours is not an easy task, Chef's mind wanders elsewhere. He starts counting the number of squares with odd side length on his chessboard..

However, Chef is not satisfied. He wants to know the number of squares of odd side length on a generic N*NN∗N chessboard.

Input:
The first line will contain a single integer TT, the number of test cases.
The next TT lines will have a single integer NN, the size of the chess board.
Output:
For each test case, print a integer denoting the number of squares with odd length.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N \leq 10001≤N≤1000
Sample 1:
Input
Output
2
3
8
10
120
*/

// solution 

void solution()
{
  
    
  int n;cin>>n;
    int ans=0;
  while(n>=0)
  {
      
      ans+=(n*n);
      n-=2;
  }
  co(ans);
}
