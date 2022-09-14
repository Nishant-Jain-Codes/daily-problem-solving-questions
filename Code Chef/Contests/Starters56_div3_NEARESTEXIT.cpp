/*
https://www.codechef.com/START56C/problems/NEARESTEXIT



Problem
There are two exits in a bus with 100100 seats:

First exit is located beside seat number 11.
Second exit is located beside seat number 100100.
Seats are arranged in a straight line from 11 to 100100 with equal spacing between any 22 adjacent seats.

A passenger prefers to choose the nearest exit while leaving the bus.

Determine the exit taken by passenger sitting on seat XX.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists a single integer XX, denoting the seat number.
Output Format
For each test case, output LEFT if the passenger chooses the exit beside seat 11, RIGHT otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings LEFT, lEft, left, and lEFT will all be treated as identical).

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq X \leq 1001≤X≤100
Sample 1:
Input
Output
6
1
50
100
30
51
73
LEFT
LEFT
RIGHT
LEFT
RIGHT
RIGHT
Explanation:
Test case 11: The exit is located beside seat 11. Hence, the passenger can take this exit without moving to any other seat.

Test case 22: To take exit at seat 11, the passenger needs to move 4949 seats. However, to take the exit at seat 100100, the passenger needs to move 5050 seats. Thus, exit at seat 11 is closer.

Test case 33: The exit is located beside seat 100100. Hence, the passenger can take this exit without moving to any other seat.

Test case 44: To take exit at seat 11, the passenger needs to move 2929 seats. However, to take the exit at seat 100100, the passenger needs to move 7070 seats. Thus, exit at seat 11 is closer.
*/

// solution 
void solution()
{
  int x;cin>>x;
    if(x>50)
    {co("RIGHT");}
    else 
    co("LEFT");
  
  
  
}
