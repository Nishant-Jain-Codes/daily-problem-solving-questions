/*
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
#include<iostream>
using namespace std;

int main(){

  // Write your code here  
int n;
cin>>n;
for(int i=1;i<=n;i++)//to print n lines
{
  for(int k=n-i;k>=1;k--) // for n-i spaces before every line
  {
    cout<<" ";
  }
  for(int j=i;j>1;j--)
  {
    cout<<j;
  }
  for(int l=1;l<=i;l++)
  {
    cout<<l;
  }
  cout<<endl;
}
  
  return 0;
}

