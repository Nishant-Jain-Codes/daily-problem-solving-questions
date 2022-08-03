/*
Problem
Chef wants to rent a car to travel to his restaurant which is NN kilometers away. He can either rent a petrol car or a diesel car.

One litre of petrol costs XX rupees and one litre of diesel costs YY rupees. Chef can travel AA kilometers with one litre of petrol and BB kilometers with one litre of diesel.

Chef can buy petrol and diesel in any amount, not necessarily integer. For example, if X = 95X=95, Chef can buy half a litre of petrol by paying 95/2 = 47.595/2=47.5 rupees.

Which car should the chef rent in order to minimize the cost of his travel?

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first and only line of each test case contains 55 space-separated integers, N, X, Y, A,N,X,Y,A, and BB - distance that chef needs to travel, the per litre prices of petrol and diesel and the distance chef can travel using one litre of petrol and diesel respectively.
Output Format
For each test case, output on a new line PETROL if the cost of travel is less using petrol car, DIESEL if the cost of travel is less using diesel car or ANY if cost of travel is same in both the cases.

You may print each character of the string in either uppercase or lowercase (for example, the strings PETrol, petrol, Petrol, and PETROL will all be treated as identical).

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N,x,y,a,b \leq 1001≤N,x,y,a,b≤100
Sample 1:
Input
Output
4
20 10 8 2 4
50 12 12 4 3
40 3 15 8 40
21 9 9 2 9
DIESEL
PETROL
ANY
DIESEL
Explanation:
Test case 11: The cost of travelling by the petrol car will be 100100 rupees while that of using the diesel car will be 4040 rupees. Hence, diesel car is better.

Test case 22: The cost of travelling by the petrol car will be 150150 rupees while that of using the diesel car will be 200200 rupees. Hence, petrol car is better.

Test case 33: The cost of travel for petrol and diesel car will be 1515 rupees.

Test case 44: The cost of travelling by the petrol car will be 94.594.5 rupees while that of using the diesel car will be 2121 rupees. Hence, diesel car is better.
*/

// solution 

void solution()
{
    float n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    float mil1 = x/a;
    float mil2 = y/b;
    
    if(n*mil1>n*mil2)
        cout<<"DIESEL"<<endl;
    else if(n*mil1<n*mil2)
        cout<<"PETROL"<<endl;
    else
         cout<<"ANY"<<endl;
    
}
