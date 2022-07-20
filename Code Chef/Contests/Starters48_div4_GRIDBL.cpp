/*

Fill The Grid Problem Code: GRIDBLSolvedSubmit
You have a grid with N rows and M columns. You have two types of tiles — one of dimensions 2×2 and the other of dimensions 1×1. You want to cover the grid using these two types of tiles in such a way that:

Each cell of the grid is covered by exactly one tile; and
The number of 1×1 tiles used is minimized.
Find the minimum number of 1×1 tiles you have to use to fill the grid.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of a single line containing two space-separated integers N,M.
Output Format
For each test case, print on a new line the minimum number of 1×1 tiles needed to fill the grid.

Constraints
1≤T≤104
1≤N,M≤104
Sample Input 1 
4
1 1
4 5
6 8
3 2
Sample Output 1 
1
4
0
2
Explanation
Test case 1: There is only one square in the grid, and it must be filled with a single 1×1 tile.

Test case 2: One way of tiling the grid using 1×1 tiles exactly 4 times is as follows:

sample 2

Test case 3: One way of tiling the grid using no 1×1 tiles is as follows:

sample 3

Test case 4: One way of tiling the grid using 1×1 tiles exactly twice is:

sample 4

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
	    int n,m;
	    cin>>n>>m;
	    if(n%2==0&&m%2==0)
	    {
	        cout<<0<<endl;
	    }
	    else if(n%2!=0&&m%2==0)
	    {
	        cout<<m<<endl;
	    }
	    else if(n%2==0&&m%2!=0)
	    {
	        cout<<n<<endl;
	    }
	    else 
	    {
	        cout<<m+n-1<<endl;
	    }

	    
	}
	return 0;
}

