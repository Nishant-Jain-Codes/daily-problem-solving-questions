/*
Problem
Chef has NN candies. He has to distribute them to exactly MM of his friends such that each friend gets equal number of candies and each friend gets even number of candies. Determine whether it is possible to do so.

NOTE: Chef will not take any candies himself and will distribute all the candies.

Input Format
First line will contain TT, number of test cases. Then the test cases follow.
Each test case contains of a single line of input, two integers NN and MM, the number of candies and the number of friends.
Output Format
For each test case, the output will consist of a single line containing Yes if Chef can distribute the candies as per the conditions and No otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings yes, Yes, yEs, and YES will all be treated as identical).

Constraints
1 \leq T \leq 10001≤T≤1000
1 \leq N,M \leq 10001≤N,M≤1000
Sample 1:
Input
Output
4
9 3
4 1
4 2
8 3
No
Yes
Yes
No
Explanation:
Test case 11: Since Chef has 99 candies and 33 friends, each friend will get \frac{9}{3} = 3 
3
9
​
 =3 candies. Since 33 is not even, Chef doesn't satisfy the conditions.

Test case 22: Since Chef has 44 candies and 11 friend, each friend will get \frac{4}{1} = 4 
1
4
​
 =4 candies. Since 44 is even, Chef satisfies all the conditions.

Test case 33: Since Chef has 44 candies and 22 friends, each friend will get \frac{4}{2} = 2 
2
4
​
 =2 candies. Since 22 is even, Chef satisfies all the conditions.

Test case 44: Since Chef has 88 candies and 33 friends. Since Chef won't be able to distribute all the candies equally, Chef does not satisfy all the conditions.
*/

// solution 
void solution()
{int n,m;
   cin>>n>>m;
   if(n%m==0&&(n/m)%2==0)// its even
    cout<<"yes";
    else 
        cout<<"No";
}
