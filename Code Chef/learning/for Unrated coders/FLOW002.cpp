/*
https://www.codechef.com/LP0TO101/problems/FLOW002


Problem
Write a program to find the remainder when an integer A is divided by an integer B.

Input
The first line contains an integer T, the total number of test cases. Then T lines follow, each line contains two Integers A and B.

Output
For each test case, find the remainder when A is divided by B, and display it in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ A,B ≤ 10000
Sample 1:
Input
Output
3 
1 2
100 200
40 15
1
100
10
*/

// solution 
//  We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include<iostream>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
          int a,b,c,d;
          cin>>a>>b;
          cout<<a%b<<endl;
     }
     return 0;
}
