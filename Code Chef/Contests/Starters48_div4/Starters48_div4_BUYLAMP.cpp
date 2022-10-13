/*

Buy Lamps Problem Code: BUYLAMPSolvedSubmit
An electronics shop sells red and blue lamps. A red lamp costs X rupees and a blue lamp costs Y rupees.

Chef is going to buy exactly N lamps from this shop. Find the minimum amount of money Chef needs to pay such that at least K of the lamps bought are red.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of a single line containing four space-separated integers N,K,X,Y.
Output Format
For each test case, output on a new line the minimum amount of money Chef needs to pay in order to buy N lamps such that at least K of the lamps bought are red.

Constraints
1≤T≤103
1≤N≤108
0≤K≤N
1≤X,Y≤10
Sample Input 1 
4
2 2 5 1
4 1 3 1
3 0 4 7
5 2 3 4
Sample Output 1 
10
6
12
15
Explanation
Test case 1: Chef buys 2 red lamps with 2⋅5=10 rupees.

Test case 2: Chef buys 1 red lamp and 3 blue lamps with 1⋅3+3⋅1=6 rupees.

Test case 3: Chef buys 3 red lamps with 3⋅4=12 rupees.

*/

// solution 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,x,y;
	    cin>>n>>k>>x>>y;
	    int m=min(x,y);
	    cout<<(k*x)+((n-k)*m)<<endl;
	    
	    
	}
	
	return 0;
}
