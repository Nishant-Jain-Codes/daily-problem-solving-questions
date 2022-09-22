/*
https://www.codechef.com/START57C/problems/MAXEXP


Problem
You are given a string SS of length NN, consisting of the digits 0-9 and the characters '+' and '-'. SS represents a valid mathematical expression.

Rearrange the characters of SS to form a valid mathematical expression such that the result obtained upon evaluating it is maximum.

If there are multiple possible answers, you may print any of them.

Note: A string SS of length NN is said to be a valid mathematical expression if the following hold:

The first character of SS is not + or -.
The last character of SS is not + or -.
Any + or - in SS must not be adjacent to another + or -.
In particular, numbers are allowed to have leading zeros, and adding/subtracting zero is fine.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of 22 lines of input.
The first line of each test case contains a single integer NN, denoting the size of the string.
The second line of each test case contains the string SS.
Output Format
For each test case, output on a new line the rearranged string giving the maximum value upon evaluation. If there are multiple possible answers, you may print any of them.

Constraints
1 \leq T \leq 10001≤T≤1000
3 \leq N \leq 10^53≤N≤10 
5
 
Each character of SS is one of \{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -\}{0,1,2,3,4,5,6,7,8,9,+,−}.
The sum of N across all test cases won't exceed 1.5 \times 10^61.5×10 
6
 .
Sample 1:
Input
Output
3
7
4-89+20
5
5-9+0
3
9-5
984+2-0
5+9-0
9-5
Explanation:
Test case 11: The given output expression evaluates to 986986, which is the maximum possible.

Test case 22: The given output expression evaluates to 1414, which is the maximum possible.

Test case 33: The given output expression evaluates to 44, which is the maximum possible.
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;
  cin>>n;
  string in;cin>>in;
  sort(in.begin(),in.end(),greater<int>());
  int p=0,m=0;
  for(int i=0;i<n;i++)
  {
      if(in[i]=='+')
      p++;
      else if(in[i]=='-')
      m++;
  }
  in =in.substr(0,n-p-m);
  int i=0;
    for(;i<in.size()-p-m;i++)
    {
        cout<<in[i];
    }
  while(p--)
  {
      cout<<'+'<<in[i++];
  }
  while(m--)
  {
      cout<<'-'<<in[i++];
  }
  cout<<endl;
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
