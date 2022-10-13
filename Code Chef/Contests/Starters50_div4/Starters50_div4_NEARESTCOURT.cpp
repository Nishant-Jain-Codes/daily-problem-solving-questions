/*
Problem
Chef and Chefina are at positions XX and YY on a number line.

They both love badminton.

It is known that badminton courts are located at every integer point.

They want to find a court such that the maximum distance travelled by either of them is minimized.

Formally, suppose they choose the badminton court at position ZZ. You need to find the minimum value of \max(|X-Z|, |Y-Z|)max(∣X−Z∣,∣Y−Z∣) across all possible choices of ZZ. Here, |X|∣X∣ denotes absolute value of XX.

Report this minimum value.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two space-separated integers XX and YY.
Output Format
For each test case, output the minimum possible value of \max(|X-Z|, |Y-Z|)max(∣X−Z∣,∣Y−Z∣).

Constraints
1 \leq T \leq 10001≤T≤1000
1 \leq X, Y \leq 10001≤X,Y≤1000
X \neq YX=Y
Sample 1:
Input
Output
4
3 5
7 6
1 10
63 31
1
1
5
16
Explanation:
Test case 11: They will choose the court at position 44 in the optimal case where both have to travel a distance of 11 unit.

Test case 22: They can either choose the court at position 66 or position 77. In both the cases one person has to travel a distance of 11 unit.
*/

// solutin 

void solution()
{
    int x,y;
    cin>>x>>y;
    int mid = (x+y)/2;
    cout<<max(abs(x-mid),abs(y-mid))<<endl;
}
