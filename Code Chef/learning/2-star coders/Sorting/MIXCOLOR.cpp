/*
https://www.codechef.com/LP2TO302/problems/MIXCOLOR?tab=statement

Chef likes to mix colors a lot. Recently, she was gifted N colors A1, A2, ..., AN by her friend.

Chef wants to make the values of all her colors pairwise distinct, as they will then look stunningly beautiful. In order to achieve that, she can perform the following mixing operation zero or more times:

Choose any two colors. Let's denote their values by x and y.
Mix the color with value x into the color with value y. After the mixing, the value of the first color remains x, but the value of the second color changes to x + y.
Find the minimum number of mixing operations Chef needs to perform to make her colors beautiful.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of colors.
The second line contains N space-separated integers A1, A2, ..., AN denoting Chef's initial colors.
Output
For each test case, print a single line containing one integer — the minimum number of required mixing operations.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109 for each valid i
Subtasks
Subtask #1 (30 points): 1 ≤ N ≤ 100

Subtask #2 (70 points): original constraints

Sample 1:
Input
Output
2
3
1 2 3
3
2 1 2
0
1
Explanation:
Example case 1: No two colors have the same value. Hence, they are already beautiful. No mixing is required.

Example case 2: Take the second color (with value x = 1) and mix it into the first color (with value x = 2). After the mixing, the colors will be 3 1 2. Now the colors are beautiful. This is the minimum number of mixing operations that are required. Hence, the answer is 1.
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
  unordered_map<int,bool> map;
  for(int i=0;i<n;i++)
  {
      int in;cin>>in;
      map[in]=true;
  }
  int ans=n-map.size();
  co(ans);
    
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
