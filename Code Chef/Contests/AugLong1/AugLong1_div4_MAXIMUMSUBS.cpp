/*
Problem
A participant can make 11 submission every 3030 seconds. If a contest lasts for XX minutes, what is the maximum number of submissions that the participant can make during it?

It is also given that the participant cannot make any submission in the last 55 seconds of the contest.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single integer XX, denoting the number of minutes.
Output Format
For each test case, output the maximum number of submissions a participant can make in XX minutes.

Constraints
1 \leq T \leq 301≤T≤30
1 \leq X \leq 301≤X≤30
Sample 1:
Input
Output
4
1
2
3
4
2
4
6
8
Explanation:
Test case 11: The contest lasts for 11 minute, which is 6060 seconds. A participant can make 22 submissions during this time — for example, in the 55-th second and in the 4848-th second. Making 33 or more submissions is impossible.

Test case 22: The contest lasts for 22 minutes, which is 120120 seconds. A participant can make 44 submissions during this time.
*/
// solution 

void solution()
{
    int x;
    cin>>x;
    cout<<2*x;
}
