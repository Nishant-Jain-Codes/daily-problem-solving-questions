/*

Code : Star Pattern
Send Feedback
Print the following pattern
Pattern for N = 4



The dots represent spaces.



Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
   *
  *** 
 *****
Sample Input 2 :
4
Sample Output 2 :
    *
   *** 
  *****
 *******

*/

// solution 

#include<iostream>
using namespace std;


int main(){

     int n;
 cin>>n;
for(int i =0;i<n;i++)
  {
   for(int b=1;b<n-i;b++)
   {
     cout<<' ';
   }
   
    for(int a=0;a<=(2*i);a++)
    {
      cout<<'*';
    }
    cout<<endl;
  }
  return 0;
  
}


