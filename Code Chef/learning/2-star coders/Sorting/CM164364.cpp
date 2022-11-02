/*

https://www.codechef.com/LP2TO302/problems/CM164364


There are nn chocolates, and you are given an array of nn numbers where the ii-th number A_iA 
i
​
  is the flavour type of the ii-th chocolate. Sebrina wants to eat as many different types of chocolates as possible, but she also has to save at least xx number of chocolates for her little brother.

Find the maximum possible number of distinct flavour types Sebrina can have.

Input:
The first line contains an integer TT --- the number of test cases.

The first line of each test case consists of two integers nn, xx - The number of chocolates Sabrina has and the number of chocolates she has to save for her brother, respectively.

The second line contains nn integers A_1,\ldots, A_nA 
1
​
 ,…,A 
n
​
 , where the ii-th chocolate has type A_iA 
i
​
 .

Output:
For each test case, output a single integer denoting the maximum possible number of distinct chocolate flavours Sabrina can eat.

Constraints
1\le T\le 101≤T≤10

1 \le x \le n \le 2 \cdot 10^51≤x≤n≤2⋅10 
5
 

1 \le A_{i} \le 10^91≤A 
i
​
 ≤10 
9
 

Sum of nn over all test cases do not exceed 2 \cdot 10^52⋅10 
5
 

Sample 1:
Input
Output
3
2 1
1 2
4 2
1 1 1 1
5 3
50 50 50 100 100
1
1
2
Explanation:
Test case 11: In the first case, the maximum number of chocolates Sebrina can have is 11 as she has to leave 11 chocolate for her brother. Thus, the maximum number of distinct chocolates is also 11.

Test case 22: Sebrina has to leave 22 chocolates for her brother. She can eat any 22 chocolates. Since all the chocolates have the same flavor, it does not matter which chocolates she eats. The maximum number of distinct chocolates would be 11.

Test case 33: Sebrina needs to save 33 chocolates for her brother. She can eat any 22 chocolates. To maximize the number of distinct chocolates, she can eat chocolates 11 and 55 with flavors 5050 and 100100 respectively. Thus maximum number of distinct chocolates is 22.
*/

// solution


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  unordered_map<int,int> map;
  int n,x;cin>>n>>x;
  for(int i=0;i<n;i++)
  {
      int Ai;cin>>Ai;
      map[Ai]++;
  }
    int uniq = map.size();
    int rep = n-uniq;
    if(x>rep)
    {
        int left = x-rep;
        co(uniq-left);
    }
    else
    {
        co(uniq);
    }
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
