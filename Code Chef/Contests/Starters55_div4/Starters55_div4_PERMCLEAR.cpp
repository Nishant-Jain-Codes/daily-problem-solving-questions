/*
https://www.codechef.com/START55D/problems/PERMCLEAR



Problem
Alice has an array AA of length NN which is initially a permutation. She dislikes KK numbers which are B_1, B_2, \ldots, B_KB 
1
​
 ,B 
2
​
 ,…,B 
K
​
  all of which are distinct. Therefore, she removes all the occurrences of these numbers from AA. The order of the remaining elements of the AA does not change.

Can you find out the resulting array AA?

Note: A permutation of length NN is an array where every integer from 11 to NN occurs exactly once.

Input Format
The first line contains a single integer TT — the number of test cases. Then the test cases follow.
The first line of each test case contains an integer NN — the size of the array AA.
The second line of each test case contains NN integers A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
  denoting the array AA.
The third line of each test case contains an integer KK — the size of the array BB.
The fourth line of each test case contains KK integers B_1, B_2, \ldots, B_KB 
1
​
 ,B 
2
​
 ,…,B 
K
​
  denoting the numbers which Alice dislikes.
Output Format
For each test case, output the resulting array AA after the removal of all occurrences of B_1, B_2, \ldots B_KB 
1
​
 ,B 
2
​
 ,…B 
K
​
 .

It is guaranteed that there will be at least one element in the resulting array.

Constraints
1 \leq T \leq 10001≤T≤1000
1 \leq K \lt N \leq 10^51≤K<N≤10 
5
 
1 \le A_i, B_i \le N1≤A 
i
​
 ,B 
i
​
 ≤N
AA is initially a permutation.
B_i \ne B_jB 
i
​
 =B 
j
​
  when (i \ne j)(i=j)
Sum of NN over all test cases does not exceed 2 \cdot 10^52⋅10 
5
 .
Sample 1:
Input
Output
3
4
4 1 3 2
2
3 1
9
5 2 9 1 8 6 4 3 7
3
5 8 9
5
3 4 5 1 2
2
2 3
4 2
2 1 6 4 3 7
4 5 1
Explanation:
Test Case 1: Here A = [4, 1, 3, 2]A=[4,1,3,2] and B = [3, 1]B=[3,1]. The resulting array AA after removing all the numbers which Alice dislikes is [4, 2][4,2].

Note that here [2, 4][2,4] is an incorrect answer since the order of elements should be the same as in the original array.

Test Case 2: Here A = [5, 2, 9, 1, 8, 6, 4, 3, 7]A=[5,2,9,1,8,6,4,3,7] and B = [5, 8, 9]B=[5,8,9]. The resulting array AA after removing all the numbers which Alice dislikes is [2, 1, 6, 4, 3, 7][2,1,6,4,3,7].

Test Case 3: Here A = [3, 4, 5, 1, 2]A=[3,4,5,1,2] and B = [2, 3]B=[2,3]. The resulting array AA after removing all the numbers which Alice dislikes is [4, 5, 1][4,5,1].
*/

// solution 

void solution()
{
  int n;cin>>n;
    int a[n];
    in(a,n);
    unordered_map<int,int*> um;
    for(int i=0;i<n;i++)
    {
        um[a[i]]=a+i;
    }
    int k;cin>>k;
    for(int i=0;i<k;i++)
    {
        int in;
        cin>>in;
        um[in]=NULL;
    }
    for(int i=0;i<n;i++)
    {
        if(a+i!=NULL)
            cout<<a[i]<<" ";
    }
    cout<<endl;
}
