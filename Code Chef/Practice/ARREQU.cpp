/*
Array Equality
Problem Code:
ARREQU
Contest Code:
LTIME111
Difficulty Rating:1281
Problem
Chef has an array of NN integers. Chef can rearrange this array in any manner.

Chef doesn’t like the array if any two adjacent elements are equal. Determine whether there exists a rearrangement of the array that Chef likes.

Input Format
The first line will contain TT - the number of test cases. Then the test cases follow.
First line of each test case contains a single integer NN - size of the array AA.
Second line of each test case contains NN space-separated integers - denoting the elements of array AA.
Output Format
For each test case, if Chef can like any rearrangement of the array print YES, otherwise print NO.

You may print each character of the string in uppercase or lowercase (for example, the strings yes, yEs, YeS, and YES will all be treated as identical).

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
2 \leq N \leq 10^52≤N≤10 
5
 
-10^9 \leq A_i \leq 10^9−10 
9
 ≤A 
i
​
 ≤10 
9
 
Sum of NN over all test cases does not exceed 2 \cdot 10^52⋅10 
5
 .
Sample 1:
Input
Output
2
5
1 1 1 1 1
3
3 3 4
No
Yes
Explanation:
Test case 11: There exists no rearrangement of the array which Chef will like.

Test case 22: A rearrangement of the array that Chef likes is [3, 4, 3][3,4,3]. Note that in this rearrangement, no two adjacent elements are equal.
*/

// solution

void solution()
{
    int n;
    cin>>n;
    unordered_map<int,int> um;
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        if(um.count(in)>0)
            um[in]++;
        else
            um[in]=1;
        if(max<um[in])
                max=um[in];
    }
    bool ans = ((n+1)/2)>=max;
    if(ans)
        cout<<yes<<endl;
    else 
        cout<<no<<endl;
}
