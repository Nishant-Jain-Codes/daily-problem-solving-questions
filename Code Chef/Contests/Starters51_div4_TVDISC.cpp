/*
Problem
Chef is looking to buy a TV and has shortlisted two models. The first one costs AA rupees, while the second one costs BB rupees.

Since there is a huge sale coming up on Chefzon, Chef can get a flat discount of CC rupees on the first TV, and a flat discount of DD rupees on the second one.

Help Chef determine which of the two TVs would be cheaper to buy during the sale.

Input Format
The first line contains a single integer TT — the number of test cases. Then the test cases follow.
The first and only line of each test case contains four space-separated integers AA, BB, CC and DD — the marked price (in rupees) of the first TV, the marked price (in rupees) of the second TV, the flat discount (in rupees) of the first TV, and the flat discount (in rupees) of the second TV.
Output Format
For each test case, print a single line containing the string First if the first TV is cheaper to buy with discount, or Second if the second TV is cheaper to buy with discount. If both of them cost the same after discount, print Any.

You may print each character of the string in uppercase or lowercase (for example, the strings first, First, fIRSt, and FIRST will all be treated as identical).

Constraints
1 \leq T \leq 50001≤T≤5000
1 \leq A, B \leq 1001≤A,B≤100
0 \leq C \leq A0≤C≤A
0 \leq D \leq B0≤D≤B
Sample 1:
Input
Output
3
85 75 35 20
100 99 0 0
30 40 0 10
First
Second
Any
Explanation:
Test case 11: The cost of the first TV after discount is 85 - 35 = 5085−35=50, while the cost of the second TV after discount is 75 - 20 = 5575−20=55. Thus the first TV is cheaper to buy than the second.

Test case 22: The cost of the first TV after discount is 100 - 0 = 100100−0=100, while the cost of the second TV after discount is 99 - 0 = 9999−0=99. Thus the second TV is cheaper to buy than the first.

Test case 33: The cost of the first TV after discount is 30 - 0 = 3030−0=30, while the cost of the second TV after discount is 40 - 10 = 3040−10=30. Since they are equal, Chef can buy any of them.
*/
// solution 

void solution()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a-c<b-d)
        cout<<"First"<<endl;
    else if(a-c>b-d)
        cout<<"Second"<<endl;
    else
        cout<<"Any"<<endl;
}
