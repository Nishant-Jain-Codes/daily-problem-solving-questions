/*
Problem
On a certain train, Chef-the ticket collector, collects a fine of Rs. XX if a passenger is travelling without a ticket. It is known that a passenger carries either a single ticket or no ticket.

PP passengers are travelling and they have a total of QQ tickets. Help Chef calculate the total fine collected.

Input Format
The first line contains a single integer TT, the number of test cases. TT lines follow. Each following line contains three integers separated by spaces, whose description follows.

The first integer, XX, is the fee in rupees.
The second integer, PP, is the number of passengers on the train.
The third integer, QQ, is the number of tickets Chef collected.
Output Format
The output must consist of TT lines.

The i^{th}i 
th
  line must contain a single integer, the total money(in rupees) collected by Chef corresponding to the i^{th}i 
th
  test case.
Constraints
1 \le T \le 101≤T≤10
1 \le X \le 101≤X≤10
0 \le Q \le P \le 100≤Q≤P≤10
Sample 1:
Input
Output
4
4 1 1
2 10 7
8 5 4
9 7 0
0
6
8
63
Explanation:
Test case 11: The total number of passengers travelling without ticket are 1 - 1 = 01−1=0. So the total fine collected is 0 \cdot 4 = 00⋅4=0 rupees.

Test case 22: The total number of passengers travelling without ticket are 10 - 7 = 310−7=3. So the total fine collected is 3 \cdot 2 = 63⋅2=6 rupees.

Test case 33: The total number of passengers travelling without ticket are 5 - 4 = 15−4=1. So the total fine collected is 1 \cdot 8 = 81⋅8=8 rupees.

Test case 44: The total number of passengers travelling without ticket are 7 - 0 = 77−0=7. So the total fine collected is 7 \cdot 9 = 637⋅9=63 rupees.
*/

// solution 

void solution()
{
    int x;cin>>x;
    int p;cin>>p;
    int q;cin>>q;
    co((p-q)*x);
}
