/*
Problem
Chef has recently introduced a feature, called WA Test Cases, which allows you to see the smallest test case that your WA code has failed in. For example, you can go to any relevant problem in Practice, make a submission which gets a WA verdict, and then click on the "Debug My Code" button to see the test case.

Your job now is to find that smallest test case that a particular submission fails on. That problem has NN test cases, and you are given the size of each of those test cases as S_1, S_2, \ldots, S_NS 
1
​
 ,S 
2
​
 ,…,S 
N
​
 . You are also given a binary string VV, which tells whether the submission has passed a particular test case or not. That is, if the i^{th}i 
th
  bit of VV is 11, that means that the submission has passed the i^{th}i 
th
  test case. If it is 00, then it has failed that test case. Your job is the output the size of the smallest test case where the submission has failed.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer, NN.
The second line contains NN integers - S_1, S_2, \ldots, S_NS 
1
​
 ,S 
2
​
 ,…,S 
N
​
 
The third line contains a binary string - VV.
Output Format
For each test case, output on a new line, a single integer, which should be the size of the smallest test case where the submission has failed.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N \leq 1001≤N≤100
1 \leq S_i \leq 1001≤S 
i
​
 ≤100
Length of V = NV=N
Each element of VV is either 00 or 11
At least one element of VV will be 00
Sample 1:
Input
Output
5
3
5 10 3
000
3
5 10 3
001
3
5 5 3
001
3
5 5 3
101
5
10 100 100 10 10
00001
3
5
5
5
10
Explanation:
Test case 1: There are 33 test cases, and the submission has failed all the 33 test cases. The sizes of the test cases on which it has failed are \{5, 10, 3\}{5,10,3}. The smallest among these is 33, and so the answer is 33.

Test case 2: There are 33 test cases, and the submission has failed on 22 test cases. The sizes of the test cases on which it has failed are \{5, 10\}{5,10}. The smallest among these is 55, and so the answer is 55.

Test case 3: There are 33 test cases, and the submission has failed on 22 test cases. The sizes of the test cases on which it has failed are \{5, 5\}{5,5}. The smallest among these is 55, and so the answer is 55.

Test case 4: There are 33 test cases, and the submission has failed on 11 test case. The sizes of the test case on which it has failed is \{5\}{5}. The smallest among these is 55, and so the answer is 55.

Test case 5: There are 55 test cases, and the submission has failed on 44 test cases. The sizes of the test cases on which it has failed are \{10, 100, 100, 10\}{10,100,100,10}. The smallest among these is 1010, and so the answer is 1010.
*/

// solution 

void solution()
{
   int n;
   cin>>n;
   vector<int> vec;
   for(int i =0;i<n;i++)
   {
       int a;
       cin>>a;
       vec.push_back(a);
   }
   string v;
   cin>>v;
   int min=INT_MAX;
   for(int i =0;i<n;i++)
   {
       
       if(min>vec[i]&&v[i]=='0')
           min = vec[i];
               
           
   }
   cout<<min;
}
