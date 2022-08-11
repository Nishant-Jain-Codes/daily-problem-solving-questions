/*
Problem
Kulyash is given an integer NN. His task is to break NN into some number of (integer) powers of 22.

TO achieve this, he can perform the following operation several times (possibly, zero):

Choose an integer XX which he already has, and break XX into 22 integer parts (YY and ZZ) such that X = Y + ZX=Y+Z.
Find the minimum number of operations required by Kulyash to accomplish his task.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single line of input.
The first and only line of each test case contains an integer NN — the original integer with Kulyash.
Output Format
For each test case, output on a new line the minimum number of operations required by Kulyash to break NN into powers of 22.

Constraints
1 \leq T \leq 10001≤T≤1000
1 \leq N \leq 10^91≤N≤10 
9
 
Sample 1:
Input
Output
2
3
4
1
0
Explanation:
Test case 11: 33 can be broken into 22 and 11 (both are powers of 22) by using 11 operation.

Test case 22: 44 is already a power of 22 so there is no need to perform any operations.
*/

// solution 

int solution()
{
    int n;
    cin>>n;
    return __builtin_popcount(n)-1;
  // gives no of '1' setbits in the number
}
