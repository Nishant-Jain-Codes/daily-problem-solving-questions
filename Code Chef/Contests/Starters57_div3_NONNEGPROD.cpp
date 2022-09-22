/*

https://www.codechef.com/START57C/problems/NONNEGPROD


Alice has an array of NN integers — A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 . She wants the product of all the elements of the array to be a non-negative integer. That is, it can be either 00 or positive. But she doesn't want it to be negative.

To do this, she is willing to remove some elements of the array. Determine the minimum number of elements that she will have to remove to make the product of the array's elements non-negative.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first line of each test case contains a single integer NN — the number of elements in the array originally.
The next line contains NN space-separated integers — A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 , which are the original array elements.
Output Format
For each test case, output on a new line the minimum number of elements that she has to remove from the array.

Constraints
1 \leq T \leq 1001≤T≤100
2 \leq N \leq 100002≤N≤10000
-1000 \leq A_i \leq 1000−1000≤A 
i
​
 ≤1000
Sample 1:
Input
Output
4
3
1 9 8
4
2 -1 9 100
4
2 -1 0 100
4
2 -1 -1 100
0
1
0
0
Explanation:
Test case 11: The product of the elements of the array is 1 \times 9 \times 8 = 721×9×8=72, which is already non-negative. Hence no element needs to be removed, and so the answer is 00.

Test case 22: The product of the elements of the array is 2 \times -1 \times 9 \times 100 = -18002×−1×9×100=−1800, which is negative. Alice can remove the element -1−1, and the product then becomes non-negative. Hence the answer is 11.

Test case 33: The product of the elements of the array is 2 \times -1 \times 0 \times 100 = 02×−1×0×100=0, which is already non-negative. Hence no element needs to be removed, and so the answer is 00.

Test case 44: The product of the elements of the array is 2 \times -1 \times -1 \times 100 = 2002×−1×−1×100=200, which is already non-negative. Hence no element needs to be removed, and so the answer is 00.
*/


// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(1)
// time complexity :  O(1)
void solution()
{
  int n;cin>>n;
  int ans=0;
  int zero=0;
  int out=0;
  for(int i=0;i<n;i++)
  {
      int in ;cin>>in;
      if(in<0)
      ans++;
      else if(in==0)
      zero++;
  }
   if(zero>0)
   out=0;
   else if(ans>0)
   {
       if(ans%2==0)
       out=0;
       else 
       out=1;
   }
  co(out);
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
