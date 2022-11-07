/*

Number Star Pattern
Send Feedback
Print the following pattern for given number of rows.
Input format :

Line 1 : N (Total number of rows)

Sample Input :
   5
Sample Output :
1234554321
1234**4321
123****321
12******21
1********1

*/

// solution 

#include<iostream>
using namespace std;

int main ()
{
    
  int n;
  cin>>n;

      for(int i = 0;i<n;i++)
      {     
          for(int a =1;a<=(n-i);a++)
          {
              cout<<a;
          }
          for(int a = 1 ;a<=(2*i);a++)
          {
              cout<<'*';
          }
          for(int a =(n-i);a>=1;a--)
          {
              cout<<a;
          }
          cout<<endl;
      }
    return 0;
}
