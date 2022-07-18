/*

Number Pattern 2
Send Feedback
Print the following pattern
Pattern for N = 4


The dots represent spaces.



Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input :
5
Sample Output :


The dots represent spaces.

*/

// solution 

#include<iostream>
using namespace std;


int main(){

      int N;
    
    cin >> N;
    for(int i = 1 ; i <=N;i++)
    {   
        for(int b=1;b<=N-i;b++)
        {
            cout<<" ";
        }
        int temp = i;
        for(int a=1;a<=i;a++)
        {   
            
            cout<<temp;
            temp++;
        }
        cout<<endl;
    }
    return 0;
  
}


