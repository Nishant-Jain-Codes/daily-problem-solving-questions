/*
Problem
Chef rented a car for a day.

Usually, the cost of the car is Rs 1010 per km. However, since Chef has booked the car for the whole day, he needs to pay for at least 300300 kms even if the car runs less than 300300 kms.

If the car ran XX kms, determine the cost Chef needs to pay.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single integer XX - denoting the number of kms Chef travelled.
Output Format
For each test case, output the cost Chef needs to pay.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq X \leq 10001≤X≤1000
Sample 1:
Input
Output
5
800
3
299
301
300
8000
3000
3000
3010
3000
Explanation:
Test case 11: The car runs for 800800 kms. Thus, he needs to pay 800\cdot 10 = 8000800⋅10=8000 rupees.

Test case 22: The car runs for 33 kms. However, since Chef booked the car for whole day, he needs to pay for at least 300300 kms. Thus, he needs to pay 300\cdot 10 = 3000300⋅10=3000 rupees.

Test case 33: The car runs for 299299 kms. However, since Chef booked the car for whole day, he needs to pay for at least 300300 kms. Thus, he needs to pay 300\cdot 10 = 3000300⋅10=3000 rupees.

Test case 44: The car runs for 301301 kms. Thus, he needs to pay 301\cdot 10 = 3010301⋅10=3010 rupees.

Test case 55: The car runs for 300300 kms. Thus, he needs to pay 300\cdot 10 = 3000300⋅10=3000 rupees.
*/
// solution 

void solution()
{
   int x;
   cin>>x;
   if(x<300)
    cout<<300*10;
    else 
    cout<<x*10;
}
