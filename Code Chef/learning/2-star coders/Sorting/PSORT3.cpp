/*
https://www.codechef.com/LP2TO302/problems/PSORT3



Problem
You are given two arrays AA and BB of size NN. We define a pair as (A_i(A 
i
​
 , B_i)B 
i
​
 ) where 0 \le i \le N - 10≤i≤N−1.

The task is to sort these pairs in decreasing order of the second elements of the pairs i.e B_iB 
i
​
 . If both the second elements are equal sort according to increasing order of the first elements of the pairs.

Output the sorted pairs in a single line with a space separating the pairs. Each pair is printed with first element followed by a space and second element. See Explanation Section for better understanding.

Input:
First line will contain a single integer NN.
Second line contains NN space separated integers A_0A 
0
​
 , A_1A 
1
​
 , ...... A_{N - 1}A 
N−1
​
  denoting the elements of array AA.
Third line contains NN space separated integers B_0B 
0
​
 , B_1B 
1
​
 , ...... B_{N - 1}B 
N−1
​
  denoting the elements of array BB.
Output:
Output in a single line 2 * N2∗N space separated integers. Output the pairs in sorted order, where the first element of a pair is from A_jA 
j
​
  and second element is from B_jB 
j
​
  with a space in between.

Constraints
1 \leq N \leq 10^51≤N≤10 
5
 
1 \leq A_i, B_i \leq 10^{18}1≤A 
i
​
 ,B 
i
​
 ≤10 
18
 
Subtasks
30 points : 1 \leq N \leq 10001≤N≤1000
70 points : Original constraints
Sample Input:
3
2 2 3
6 3 3
Sample Output:
2 6 2 3 3 3
### EXPLANATION:
The pairs are:

(2, 6)(2,6)
(2, 3)(2,3)
(3, 3)(3,3)
We are required to sort these pairs in decreasing order of second elements and then increasing order of first elements. Therefore, pairs sorted:

(2, 6)(2,6)
(2, 3)(2,3)
(3, 3)(3,3)
You can clearly see that the second elements are in decreasing order from top to bottom and when second elements of two pairs are equal they are sorted in increasing order of first elements from top to bottom. We print the pairs as follows:

2\ 6\ 2\ 3\ 3\ 32 6 2 3 3 3

The first two elements correspond to pair 1 in sorted list. The next two elements correspond to pair 2 in sorted list. The last two elements correspond to pair 3 from sorted list.
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)

bool comp (pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second<p2.second)
        return false;
    else if(p1.second>p2.second)
        return true;
    else 
        {
            if(p1.first<p2.first)
                return true;
            else 
                return false;
        }
}
void solution()
{
  int n;cin>>n;
    int a[n];
    in(a,n);
    int b[n];
    in(b,n);
    vector<pair<int,int>> vectpair;
    for(int i=0;i<n;i++)
    {
        vectpair.push_back({a[i],b[i]});
    }
  
   sort(vectpair.begin(),vectpair.end(),comp);
    for(int i=0;i<n;i++)
    {
        pair<int,int> p1 = vectpair[i];
        cout<<p1.first<<" "<<p1.second<<" ";
    }
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
