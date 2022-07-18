/*

Code : Triangle of Numbers
Send Feedback
Print the following pattern for the given number of rows.
Pattern for N = 4



The dots represent spaces.



Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Constraints :
0 <= N <= 50
Sample Input 1:
5
Sample Output 1:
           1
         232
       34543
     4567654
   567898765
Sample Input 2:
4
Sample Output 2:
           1
         232
       34543
     4567654

*/

// solution 

#include <iostream>
using namespace std;

int main() {
  int n;
 cin>>n;
 
for(int i =1;i<=n;i++)
  { 
   for(int a=1;a<=(n-i);a++)
   {
     cout<<' '; 
   }
   int k = i;
   for(int b=1;b<=i;b++)
   {
     cout<<k;
     k++;
   }
   for(int l=k-1;l>i;l= l-1)
   {
     cout<<l-1;
   }
    cout<<endl;
  }
  return 0;
}
