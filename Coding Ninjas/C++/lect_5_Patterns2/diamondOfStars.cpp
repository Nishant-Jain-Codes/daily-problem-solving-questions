/*

Code : Diamond of stars
Send Feedback
Print the following pattern for the given number of rows.
Note: N is always odd.


Pattern for N = 5



The dots represent spaces.



Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  *

*/

// solution 

#include<iostream>
using namespace std;


int main() {
  int n;
 cin>>n;
 int k1 =1;
 int s = 2;
 int k2=0;
 int m=0;
 if(n%2==0)
 {
   k2 = n - (n/2) + 1;
   m=0;
 }
 else
 {
    k2 =   n - (n/2);
    m=1;
 }
for(int i = 1; i<=n;i++)
{
  if(k1<=k2)
  {
    for(int a = 1;a<=(n-(n/2)-i+1-m);a++)
    {
      cout<<" ";
    }
    
    for(int b=1;b<(2*i);b++)
    {
      cout<<'*';
      
    }
    cout<<endl;
    k1++;
  }
  else
  {
    for(int a = 1;a<=s-m;a++)
    {
      cout<<' ';
    }
    s++;
    for(int a = 1;a<=2*(n-i)+1;a++)
    {
      cout<<'*';
    }
    cout<<endl;
  }
}
  return 0;
}
