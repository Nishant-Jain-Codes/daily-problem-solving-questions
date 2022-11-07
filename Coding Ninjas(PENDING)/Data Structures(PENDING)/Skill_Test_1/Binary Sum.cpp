/*
Ninja is playing with Binary Strings at his Granny’s house. Granny is always encouraging Ninja to practice math. So she has given him two binary strings. He has to return their sum as a binary string. Can you do it for Ninja?
Input Format:
First line of input contains an integer t, representing the number of test cases.
First line of input of each test case contains the first binary string.
Second line of input each test case contains the second binary string.
Constraints:
1 <= t <= 100
1 <= length of each string <= 10000
Time Limit: 1 second
Output Format:
For each query, you have to print the sum of the two given binary strings as a binary string.
Sample Input 1:
1
1010001
1101
Sample Output 1:
1011110
Sample Input 2:
2
11001100
10
10000001
111101
Sample Output 2:
11001110
10111110
*/
#include<bits/stdc++.h>
using namespace std;
void solution()
{
    string b,s;
    cin>>b>>s;
    if(b.size()<s.size())
        swap(b,s);
    int carry=0;
    
    int i=s.size()-1;
    for(int j=b.size()-1;j>=0;j--)
    {
        //cout<<j<<" "<<i;
        int no1,no2;
        if(i<0)
            no2=0;
        else 
        {
            no2= s[i]-'0';
            i--;
        }
            no1= b[j]-'0';
        int fno = no1+no2+carry;
        
        carry=fno/2;
        
        fno%=2;
        
        if(fno==1)
            b[j]='1';
        else 
            b[j]='0';
        //cout<<b[j];
    }
	if(carry==1)
        cout<<1;
    cout<<b<<endl;
}
int main() {

	// Write your code here
	int t;
	cin>>t;
	while(t--)
	{
		solution();
	}
}
