/*
https://www.codechef.com/START57C/problems/EVENSPLIT


You are given a binary string SS of length NN. You can perform the following operation on it:

Pick any non-empty even-length subsequence of the string.
Suppose the subsequence has length 2k2k. Then, move the first kk characters to the beginning of SS and the other kk to the end of SS (without changing their order).
For example, suppose S = 01100101110S=01100101110. Here are some moves you can make (the chosen subsequence is marked in red):

0\textcolor{red}{1}10\textcolor{red}{0}101110 \to \textcolor{red}{1}010101110\textcolor{red}{0}01100101110→10101011100
01\textcolor{red}{10}01\textcolor{red}{0}1\textcolor{red}{1}10 \to \textcolor{red}{10}0101110\textcolor{red}{01}01100101110→10010111001
011\textcolor{red}{00101110} \to \textcolor{red}{0010}011\textcolor{red}{1110}01100101110→00100111110
What is the lexicographically smallest string that can be obtained after performing this operation several (possibly, zero) times?

Note: A binary string AA is said to be lexicographically smaller than another binary string BB of the same length if there exists an index ii such that:

A_1 = B_1, A_2 = B_2, \ldots, A_{i-1} = B_{i-1}A 
1
​
 =B 
1
​
 ,A 
2
​
 =B 
2
​
 ,…,A 
i−1
​
 =B 
i−1
​
 
A_i = 0A 
i
​
 =0 and B_i = 1B 
i
​
 =1.
Input Format
The first line of input will contain a single integer TT, denoting the number of test cases. The description of the test cases follows.
Each test case consists of two lines of input.
The first line of each test case contains a single integer NN, the length of string SS.
The second line contains a binary string of length NN.
Output Format
For each testcase, output a single line containing the lexicographically shortest binary string that can be obtained by performing the given operation several times.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \leq N \leq 2\cdot 10^51≤N≤2⋅10 
5
 
SS is a binary string, i.e, contains only the characters 00 and 11.
The sum of NN across all test cases won't exceed 2\cdot 10^52⋅10 
5
 .
Sample 1:
Input
Output
4
2
10
4
1001
5
11111
7
0010100
10
0011
11111
0000011
Explanation:
Test case 11: There's only one move possible, and it gives back the original string when made. So, SS cannot be changed, and the answer is 1010.

Test case 22: Make the following moves:

1\textcolor{red}{0}0\textcolor{red}{1} \to \textcolor{red}{0}10\textcolor{red}{1}1001→0101
\textcolor{red}{01}01 \to \textcolor{red}{0}01\textcolor{red}{1}0101→0011
This is the lexicographically smallest string.

Test case 33: Performing any move doesn't change the string.

Test case 44: Make the move \textcolor{red}{001}0\textcolor{red}{1}00 \to \textcolor{red}{00}000\textcolor{red}{11}0010100→0000011.
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
  string in;cin>>in;
  int no1=0;
  for(int i=0;i<n;i++)
  {
      if(in[i]=='1')
      no1++;
  }
  if(n<=2)
  {
      co(in);
  }
  else 
  {
      for(int i=0;i<n-no1;i++)
      {
          cout<<'0';
      }
      for(int i=0;i<no1;i++)
      {
          cout<<'1';
      }
      cout<<endl;
  }
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
