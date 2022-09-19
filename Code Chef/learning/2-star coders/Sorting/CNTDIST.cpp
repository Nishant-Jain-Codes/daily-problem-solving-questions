/*
https://www.codechef.com/LP2TO302/problems/CNTDIST



Given an array of size nn, find the number of distinct elements in the array.
Chef already tried an attempt to solve the above problem and he came up with this code.

The approach is simple, for each new number that is obtained, iterate over the previously obtained numbers and if a match is found then add one to the count of distinct numbers obtained so far, otherwise leave it as is (add zero).

However when Chef submitted the above code he got Time Limit Exceeded.

Determine the worst case time complexity of Chef's code.

It can be shown that the worst case time complexity is \mathcal{\Theta}(n^a)Θ(n 
a
 ) where aa is an integer.

First find the value of aa, and then optimise Chef's code using the data structures that you have learnt.

(Hint: Think about sets/ dictionary and how it could be used to solve this problem.)

Input
First line contains an integer nn, the size of the array
Next nn lines each contain a single integer, the elements of the array.
Output
Print two lines. In the first line print the value of aa where the worst case time complexity of Chef's code is \Theta(n^a)Θ(n 
a
 ). In the second line, print a single integer, the number of distinct values in the given array.

Constraints
1 \leq n \leq 10^51≤n≤10 
5
 
0 \leq A_i \leq 10^90≤A 
i
​
 ≤10 
9
 
The elements of the array are generated uniformly randomly among the given constraints.
Sample Input
3
1
2
1
```### Sample Output
2

In order to not give away the answer, the first line is given as "*". Note that this is not the correct answer but just a placeholder to explain the output format.

The given array contains the values $1$ and $2$ ($1$ repeated twice), hence the number of distinct values is $2$, and is printed in the second line.
*/

// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;
  cin>>n;
  unordered_map<int,bool> map;
 
  for(int i=0;i<n;i++)
  {
      int in;cin>>in;
     
          map[in]=true;
     
  }
    co(2);
  co(map.size());
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
