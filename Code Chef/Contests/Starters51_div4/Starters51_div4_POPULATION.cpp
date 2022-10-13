/*
Problem
There were initially XX million people in a town, out of which YY million people left the town and ZZ million people immigrated to this town.

Determine the final population of town in millions.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first and only line of each test case consists of three integers XX, YY and ZZ.
Output Format
For each test case, output the final population of the town in millions.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq X, Y, Z \leq 101≤X,Y,Z≤10
Y \leq XY≤X
Sample 1:
Input
Output
4
3 1 2
2 2 2
4 1 8
10 1 10
4
2
11
19
Explanation:
Test case 11: The initial population of the town was 33 million, out of which 11 million people left and 22 million people entered the town. So, final population = 3 - 1 + 2 = 4=3−1+2=4 million.

Test case 22: The initial population of the town was 22 million, out of which 22 million left and 22 million immigrated. The final population is thus 2+2-2 = 22+2−2=2 million.
*/

// solution 


void solution()
{
   int x,y,z;
   cin>>x>>y>>z;
   cout<<x-y+z<<endl;
}
