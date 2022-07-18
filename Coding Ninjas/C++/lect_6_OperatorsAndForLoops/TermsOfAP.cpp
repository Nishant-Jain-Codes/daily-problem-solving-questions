/*

Terms of AP
Send Feedback
Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
Input format :
Integer x
Output format :
Terms of series (separated by space)
Constraints :
1 <= x <= 1,000
Sample Input 1 :
10
Sample Output 1 :
5 11 14 17 23 26 29 35 38 41
Sample Input 2 :
4
Sample Output 2 :
5 11 14 17

*/

// solution 

#include<iostream>
using namespace std;

int main() {
	int x;
    cin>>x;
    for (int n = 1; n<=x; n++)
    {
        if(((3*n)+2)%4==0)
        {	
            x++;
            continue;
        }
        else
        {
        	cout<<  (3*n)+2<<' ';  
        }
    }
	return 0;
}
