/*
https://www.codechef.com/LP2TO301/problems/MAKEDIV3?tab=statement


Problem
Given an integer NN, help Chef in finding an NN-digit \textbf{odd positive integer}odd positive integer XX such that XX is divisible by 33 but not by 99.

\textbf{Note}:Note: There should not be any leading zeroes in XX. In other words, 003003 is not a valid 33-digit odd positive integer.

Input Format
The first line of input contains a single integer TT, denoting the number of testcases. The description of the TT testcases follows.
The first and only line of each test case contains a single integer NN, denoting the number of digits in XX.
Output Format
For each testcase, output a single line containing an NN-digit odd positive integer XX in decimal number system, such that XX is divisible by 33 but not by 99.

Constraints
1 \leq T \leq 5001≤T≤500
1 \leq N \leq 10^41≤N≤10 
4
 
The sum of NN over all test cases does not exceed 10^510 
5
 
Sample 1:
Input
Output
3
1
2
3
3
15
123
Explanation:
Test Case 11: 33 is the only 11-digit odd positive integer which is divisible by 33 but not by 99.

Test Case 22: 1515 is a 22-digit odd positive integer which is divisible by 33 but not by 99. 2121 is also a valid answer, among others. Note that 0303 is not a valid answer as there should not be any leading zeroes in the output.
*/

// solution 


void solution()
{
  
    int n;
    cin>>n;
    //int ans;
    
    if(n==1)
        {co(3);}
    else 
        {
           string ans=""; 
           for(int i=1;i<=n;i++)
           {
               if(i==1||i==n)
               ans+='3';
               else 
               ans+='0';
           }
           co(ans);
        }
    
  
  
  
}
