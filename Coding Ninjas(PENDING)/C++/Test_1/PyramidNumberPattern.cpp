/*

Pyramid Number Pattern
Send Feedback
Print the following pattern for the given number of rows.
Pattern for N = 4
   1
  212
 32123
4321234
Input format : N (Total no. of rows)

Output format : Pattern in N lines

Sample Input :
5
Sample Output :
        1
      212
    32123
  4321234
543212345

*/

// solution 

#include<iostream>
using namespace std;

int main ()
{
    
  int n;
  cin>>n;

      for(int i = 1;i<=n;i++)
      {     
          for(int a=1;a<=(n-i);a++)
          {
              cout<<' ';
          }
          for(int a=i;a>0;a--)
          {
              cout<<a;
          }
          for(int a=2;a<=i;a++)
          {
              cout<<a;
          }
          cout<<endl;
      }
    return 0;
}
