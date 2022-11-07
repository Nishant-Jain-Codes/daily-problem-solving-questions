/*

Binary to decimal
Send Feedback
Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)
Constraints :
0 <= N <= 10^9
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7

*/

// solution 

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	long bin;
    cin>>bin;
    long ans=0;
    int k=0;
    for(long a  = bin ; a>0;a/=10)
    {
        ans = ans + (pow(2,k)*(a%10));
        k++;
    }
	cout<<ans;
}
