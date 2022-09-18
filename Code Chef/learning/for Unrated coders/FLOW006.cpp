/*
https://www.codechef.com/LP0TO101/problems/FLOW006


You're given an integer N. Write a program to calculate the sum of all the digits of N.

Input
The first line contains an integer T, the total number of testcases. Then follow T lines, each line contains an integer N.

Output
For each test case, calculate the sum of digits of N, and display it in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
3 
12345
31203
2123
Output
15
9
8
*/
// solution 
//  We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int sum=0;
        
        while(n>0)
        {
            sum+=(n%10);
            n/=10;
        }
        
        cout<<sum<<"\n";
        
    }
	return 0;
}
