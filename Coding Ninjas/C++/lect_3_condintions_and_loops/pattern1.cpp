/*

Number Pattern 1
Send Feedback
Print the following pattern
Pattern for N = 4
1
23
345
4567
Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input 1 :
3
Sample Output 1 :
1
23
345

*/

// solution 

#include<iostream>
using namespace std;


int main(){

        int N;
    
    cin >> N;
    for(int i = 1 ; i <=N;i++)
    {   
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


