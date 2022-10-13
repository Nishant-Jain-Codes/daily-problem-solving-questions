/*
Problem
There are three people sitting in a room - Alice, Bob, and Charlie. They need to decide on the temperature to set on the air conditioner. Everyone has a demand each:

Alice wants the temperature to be at least AA degrees.
Bob wants the temperature to be at most BB degrees.
Charlie wants the temperature to be at least CC degrees.
Can they all agree on some temperature, or not?

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single line which contains three integers - A, B, CA,B,C.
Output Format
For each test case, output on a new line, "Yes" or "No". "Yes", if they can decide on some temperature which fits all their demands. Or "No", if no temperature fits all their demands.

You may print each character of the string in either uppercase or lowercase (for example, the strings NO, nO, No, and no will all be treated as identical).

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq A, B, C \leq 1001≤A,B,C≤100
Sample 1:
Input
Output
4
30 35 25
30 35 40
30 35 35
30 25 35
Yes
No
Yes
No
Explanation:
Test Case 1: Alice wants the temperature to be \ge 30≥30, Bob wants it to be \le 35≤35, and Charlie wants it to be \ge 25≥25. The temperatures 30, 31, 32, 33, 34, 3530,31,32,33,34,35 all satisfy all their demands. So they can choose any of these 6 temperatures, and so the answer is "Yes".

Test Case 2: Alice wants the temperature to be \ge 30≥30, Bob wants it to be \le 35≤35, and Charlie wants it to be \ge 40≥40. A number can't be both \ge 40≥40, and \le 35≤35. So there is no temperature that satisfies all their demands. So the answer is "No".

Test Case 3: Alice wants the temperature to be \ge 30≥30, Bob wants it to be \le 35≤35, and Charlie wants it to be \ge 35≥35. The temperature 3535 satisfies all their demands. So the answer is "Yes".

Test Case 4: Alice wants the temperature to be \ge 30≥30, Bob wants it to be \le 25≤25, and Charlie wants it to be \ge 35≥35. A number can't be both \ge 30≥30, and \le 25≤25. So there is no temperature that satisfies all their demands. So the answer is "No".
*/

// solution 

void solution()
{
   int a,b,c;
   bool ans=false;
    cin>>a>>b>>c;
    if((a<=b&&c<=b))
        ans = true;
    if(ans)
        cout<<"YES";
    else
        cout<<"NO";
}
