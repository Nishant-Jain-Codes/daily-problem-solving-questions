/*

Construct N
Problem Code:
CONN
Contest Code:
START47
Difficulty Rating:860


Problem
You are given an integer NN. Find if it is possible to represent NN as the sum of several(possibly zero) 22's and several(possibly zero) 77's.

Formally, find if there exist two integers X, Y \ (X, Y \ge 0)X,Y (X,Y≥0) such that 2 \cdot X + 7\cdot Y = N2⋅X+7⋅Y=N.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single line containing an integer NN.
Output Format
For each test case, print on a new line YES if it is possible to represent NN as the sum of several(possibly zero) 22's and several(possibly zero) 77's and NO otherwise.

You may print each character of the string in either uppercase or lowercase (for example, the strings yEs, yes, Yes, and YES will all be treated as identical).

Constraints
1 \leq T \leq 10001≤T≤1000
1 \leq N \leq 10^81≤N≤10 
8
 
Sample 1:
Input
Output
4
2
5
7
11
YES
NO
YES
YES
Explanation:
Test case 11: 2 \cdot 1 + 7\cdot 0 = 22⋅1+7⋅0=2.

Test case 22: It is impossible to express 55 as a sum of several 22's and 77's.

Test case 33: 2 \cdot 0 + 7\cdot 1 = 72⋅0+7⋅1=7.

Test case 44: 2 \cdot 2 + 7\cdot 1 = 112⋅2+7⋅1=11.
*/

// solution 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n%7==0||n%2==0||(n%2==1&&n>7))
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
