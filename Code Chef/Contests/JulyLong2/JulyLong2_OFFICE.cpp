/*

Problem
Recently Chef joined a new company. In this company, the employees have to work for XX hours each day from Monday to Thursday. Also, in this company, Friday is called Chill Day — employees only have to work for YY hours (Y \lt X)(Y<X) on Friday. Saturdays and Sundays are holidays.

Determine the total number of working hours in one week.

Input Format
The first line contains a single integer TT — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space-separated integers XX and YY — the number of working hours on each day from Monday to Thursday and the number of working hours on Friday respectively.
Output Format
For each test case, output the total number of working hours in one week.

Constraints
1 \leq T \leq 1001≤T≤100
2 \leq X \leq 122≤X≤12
1 \le Y \lt X1≤Y<X
Sample 1:
Input
Output
3
10 5
12 2
8 7
45
50
39
Explanation:
Test case 11: The total number of working hours in a week are: 10 \texttt{(Monday)} + 10 \texttt{(Tuesday)} + 10 \texttt{(Wednesday)} + 10 \texttt{(Thursday)} + 5 \texttt{(Friday)} = 4510(Monday)+10(Tuesday)+10(Wednesday)+10(Thursday)+5(Friday)=45

Test Case 2: The total number of working hours in a week are: 12 \texttt{(Monday)} + 12 \texttt{(Tuesday)} + 12 \texttt{(Wednesday)} + 12 \texttt{(Thursday)} + 2 \texttt{(Friday)} = 5012(Monday)+12(Tuesday)+12(Wednesday)+12(Thursday)+2(Friday)=50

Test Case 3: The total number of working hours in a week are: 8 \texttt{(Monday)} + 8 \texttt{(Tuesday)} + 8 \texttt{(Wednesday)} + 8 \texttt{(Thursday)} + 7 \texttt{(Friday)} = 398(Monday)+8(Tuesday)+8(Wednesday)+8(Thursday)+7(Friday)=39

accepted
Accepted
6596
total-Submissions
Submissions
7203

*/

// solution 

#include <iostream>
using namespace std;

void solution()
{
    int x,y;
    cin>>x>>y;
    cout<<(4*x)+y<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    solution();
	}
	return 0;
}
