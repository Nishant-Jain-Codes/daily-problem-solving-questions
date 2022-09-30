/*

https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/?fbclid=IwAR2XcdRMJnGwG3ojY4diVU80L41VtxP85xk2VWMZ_lUYz58kKYk2TtZN3rc


Problem
You have been given an integer array A and a number K. Now, you need to find out whether any two different elements of the array A sum to the number K. Two elements are considered to be different if they lie at different positions in the array. If there exists such a pair of numbers, print "YES" (without quotes), else print "NO" without quotes.

Input Format:

The first line consists of two integers N, denoting the size of array A and K. The next line consists of N space separated integers denoting the elements of the array A.

Output Format:

Print the required answer on a single line.

Constraints:




Sample Input
5 9
1 2 3 4 5
Sample Output
YES
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
Here, . So, the answer is YES.
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)

void solution()
{
    int n,k;
    cin>>n>>k;
    unordered_map<int,bool> map;
    for(int i=0;i<n;i++)
    {
        int  l;cin>>l; 
        map[l]=true;

    }
    for(auto x:map)
    {
        if(map.count(abs(k-x.first))>0)
            {
                co("YES");
                return ;
            }

    }

    co("NO");
    
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
