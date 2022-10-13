/*
https://www.codechef.com/START57C/problems/TWODIFFPALIN


Problem
You are given two positive integers AA and BB. You need to construct two different binary strings (i.e, they are strings which consist of only 00s and 11s), which satisfy these two conditions:

Both the strings should be palindromes.
Each string should have exactly AA 00s, and exactly BB 11s in them.
Output Yes if two such different binary strings can be constructed and No otherwise.

Note:

A string is said to be a palindrome, if the string and the reverse of the string are identical.
Two strings are said to be different if either their lengths are different, or if they differ in at least one character.
Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case contains two space-separated integers, AA and BB, in a new line.
Output Format
For each test case, output on a new line 'Yes', if you can construct two different binary strings satisfying the conditions. If not, output No.

You may print each character of the string in uppercase or lowercase (for example, the strings YeS, yes, YES, and YEs will all be treated as identical).

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \leq A, B \leq 10^61≤A,B≤10 
6
 
Sample 1:
Input
Output
3
2 2
2 3
3 3
Yes
Yes
No
Explanation:
Test case 11: Consider the binary strings 01100110 and 10011001. Both of them are palindromes, and both of them have exactly 22 00s, and 22 11s. Hence we can construct them, and so the answer is Yes.

Test case 22: Consider the binary strings 0111001110 and 1010110101. Both of them are palindromes, and both of them have exactly 22 00s, and 33 11s. Hence we can construct them, and so the answer is Yes.

Test case 33: There is no way to construct two such different strings. Hence the answer is No.

*/

// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(1)
// time complexity :  O(1)
void solution()
{
  int a,b;cin>>a>>b;
    bool ans= ((a%2==0&&b%2==0)||(a%2==0&&b%2!=0)||(a%2!=0&&b%2==0))&&(a>=2&&b>=2);
    YorN(ans);

}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
