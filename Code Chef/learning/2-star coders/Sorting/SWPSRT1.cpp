/*
https://www.codechef.com/LP2TO302/problems/SWPSRT1


Swap Sort
You are given an array AA of size nn (not exceeding 500500), you are allowed a maximum of n-1n−1 swaps where in each swap you can choose any two indices i, ji,j such that 0 \leq i, j \leq n-10≤i,j≤n−1 and swap the values of A_iA 
i
​
  and A_jA 
j
​
 .

Note that you do not need to minimise the number of swaps, and you are also not required to optimize the time complexity (note that the constraints allow solutions that are \mathcal{O}(n^2)O(n 
2
 ) as well), however you cannot swap more than n-1n−1 times.

There may be many solutions, you can output any of them.

Input
The first line contains a single integer nn, the number of elements in the array

The second line contains nn space separated integers, the elements of the array

Output
In the first line print the number of swaps you need to perform, let this number be mm.

In the next mm lines, print two space separated integers i, ji,j such that 0 \leq i, j \leq n-10≤i,j≤n−1.

After performing the swaps in the order in which your program gives the output, the array should become sorted in increasing order. (i.e. A_i \geq A_{i-1}A 
i
​
 ≥A 
i−1
​
  for every ii in the range [1, n-1][1,n−1]).

Constraints
1 \leq n \leq 5001≤n≤500

-10^9 \leq A_i \leq 10^9−10 
9
 ≤A 
i
​
 ≤10 
9
 

Sample Input
3
3 2 1
Sample Output
1
0 2
Explanation
After the first swap, the elements A_0A 
0
​
  and A_2A 
2
​
  are swapped, and the array becomes sorted, i.e. \{1, 2, 3\}{1,2,3}
*/


// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)
void solution()
{
  int n;cin>>n;
    int main[n],copy[n];
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        main[i]=in;
        copy[i]=in;
    }
    sort(copy,copy+n);
    int ans=0;
    vector<pair<int,int>> ansPair;
    for(int i=0;i<n-1;i++)
    {
        if(main[i]!=copy[i])
        {
            int find=copy[i];
            for(int j=i+1;j<n;j++)
            {
                if(main[j]==find)
                {
                    swap(main[i],main[j]);
                    ans++;
                    ansPair.push_back({i,j});
                    break;
                }
            }
        }
    }
    
    co(ans);
    for(int i=0;i<ansPair.size();i++)
    {
        pair<int,int> p =ansPair[i];
        cout<<p.first<<" "<<p.second<<endl;
    }
    
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
