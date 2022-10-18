/*
https://www.codechef.com/LP2TO301/problems/NFS

Chef is playing Need For Speed. Currently, his car is running on a straight road with a velocity UU metres per second and approaching a 90^{\circ}90 
∘
  turn which is SS metres away from him. To successfully cross the turn, velocity of the car when entering the turn must not exceed VV metres per second.

The brakes of Chef's car allow him to slow down with a deceleration (negative acceleration) not exceeding AA metres per squared second. Tell him whether he can cross the turn successfully. The velocity vv when entering the turn can be determined from Newton's 2nd law to be v^2 = U^2 + 2 \cdot a \cdot Sv 
2
 =U 
2
 +2⋅a⋅S if the car is moving with a uniform acceleration aa.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains four space-separated integers UU, VV, AA and SS.
Output
For each test case, print a single line containing the string "Yes" if Chef can cross the turn successfully or "No" if he cannot (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \leq U, V, A, S \leq 10^41≤U,V,A,S≤10 
4
 
Subtasks
Subtask #1 (100 points): original constraints

Sample 1:
Input
Output
3
1 1 1 1
2 1 1 1
2 2 1 1
Yes
No
Yes
Explanation:
Example case 1: Since U = V = 1U=V=1, Chef does not need to brake and will be able to turn successfully.

Example case 2: The smallest velocity Chef's car can have even with the maximum deceleration is \sqrt{2 \cdot 2 - 2 \cdot 1 \cdot 1} = \sqrt{2} 
2⋅2−2⋅1⋅1
​
 = 
2
​
 , which is greater than the maximum allowed velocity for a safe turn.

Example case 3: The smallest velocity Chef's car can have with the maximum deceleration is again \sqrt{2} 
2
​
 , which is smaller than the maximum allowed velocity for a safe turn.
*/

// solution

void solution()
{
    int u,v,a,s;
    cin>>u>>v>>a>>s;
    int rhs = (u*u) - (2*a*s);
    int lhs  = v*v;
    if(lhs>=rhs)
        {co(yes);}
    else 
        co(no);
    
  
  
  
}
