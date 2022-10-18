/*
https://www.codechef.com/LP0TO101/problems/FLOW007


Problem
Given an Integer N, write a program to reverse it.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
For each test case, display the reverse of the given number N, in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Sample 1:
Input
Output
4
12345
31203
2123
2300
54321
30213
3212
32
*/

// solution 

//  We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,reverse=0,r;
        cin>>n;
        for(;n>0;n=n/10){
            r=n%10;
            reverse=reverse*10+r;
        }
        cout<<reverse<<endl;
    }
	return 0;
}

