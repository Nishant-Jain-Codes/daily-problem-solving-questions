/*

All Prime Numbers
Send Feedback
Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.
Input Format :
Integer N
Output Format :
Prime numbers in different lines
Constraints :
1 <= N <= 100
Sample Input 1:
9
Sample Output 1:
2
3
5
7
Sample Input 2:
20
Sample Output 2:
2
3
5
7
11
13
17
19

*/

// solution 

#include<iostream>
using namespace std;


//all prime no 
int main()
{   
    int n;
    cin>>n;
   
    for(int i = 2;i<=n ; i++)
    {
        bool prime = true;
        for(int a = 2;a<=(i/2);a++)
        {
            if(a==i)
            {
                prime = true;
                break;
            }
            else if(i%a==0)
            {   
                prime = false;
                break;
            }
            else
            {
                prime = true;
            }
       
        }
         if(prime)
        {
            cout<<i<<endl;
        }
    }
   
    return 0;

}
