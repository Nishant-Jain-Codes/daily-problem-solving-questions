/*
Problem
Given an integer NN, determine the number of pairs (A, B)(A,B) such that:

1 \leq A, B \leq N1≤A,B≤N;
A + BA+B is odd.
Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single integer NN.
Output Format
For each test case, output the number of required pairs.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N \leq 10^91≤N≤10 
9
 
Sample 1:
Input
Output
5
1
2
3
100
199
0
2
4
5000
19800
Explanation:
Test case 11: There are no pairs satisfying the given conditions.

Test case 22: The pairs satisfying both conditions are: (1, 2)(1,2) and (2, 1)(2,1).

Test case 33: The pairs satisfying both conditions are: (1, 2), (2, 1), (2, 3),(1,2),(2,1),(2,3), and (3, 2)(3,2).
*/
// solution 
void solution()
{
   int n;
   cin>>n;
   int odd;
   int even;
   if(n%2==0)
   {
       odd=n/2;
       even=n/2;
   }
   else
   {
       odd=(n/2)+1;
       even=n-odd;
   }
   int ans=(odd*even)*2;
   cout<<ans;
}
