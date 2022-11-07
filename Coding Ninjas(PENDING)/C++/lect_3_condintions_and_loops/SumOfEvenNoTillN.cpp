/*

Sum of Even Numbers till N
Send Feedback
Given a number N, print sum of all even numbers from 1 to N.
Input Format :
Integer N
Output Format :
Required Sum 
Sample Input 1 :
 6
Sample Output 1 :
12

*/

// solution 

#include<iostream>
using namespace std;


int main(){

int n ;
cin>>n;
int sum = 0;
for (int i = 2 ;i <= n;i+=2)
{
    sum = sum + i;
}
cout<<sum<<endl;
return 0;
}
