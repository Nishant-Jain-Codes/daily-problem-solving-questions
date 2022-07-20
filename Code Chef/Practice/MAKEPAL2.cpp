/*

Make Palindrome 2
Problem Code:
MAKEPAL2
Contest Code:
START48
Difficulty Rating:1393
ADVERTISEMENT

Want to Remove Ads ?
Upgrade To Pro
Problem
You are given a binary string SS of length NN. You want to obtain a palindrome from SS by applying the following operation at most \left\lfloor \frac{N}{2} \right\rfloor⌊ 
2
N
​
 ⌋ times:

Choose an index i\;(1 \le i \le \lvert S \rvert)i(1≤i≤∣S∣), delete the character S_iS 
i
​
  from SS and concatenate the remaining parts of the string. Here \lvert S \rvert∣S∣ denotes the current length of string SS.
For example, if S =S= 11010, then applying the operation on index i=2i=2 makes S=S= 1010.

Note that after each operation, the length of the string SS decreases by one.

Find any palindrome you can obtain after the operations. It can be proved that it is always possible to obtain a palindrome from SS under the given constraints.

Here, \left\lfloor \frac{N}{2} \right\rfloor⌊ 
2
N
​
 ⌋ denotes floor division of the integer NN by 22. For example, \left\lfloor \frac{5}{2} \right\rfloor = 2⌊ 
2
5
​
 ⌋=2, \left\lfloor \frac{8}{2} \right\rfloor = 4⌊ 
2
8
​
 ⌋=4. A binary string is a string that consists of only the characters 0 and 1.

Input Format
The first line of input contains an integer TT, denoting the number of test cases. The TT test cases then follow:
The first line of each test case contains an integer NN, denoting the length of the binary string SS.
The second line of each test case contains the binary string SS.
Output Format
For each test case, print on a separate line any palindromic string that can be obtained from SS by applying the given operation at most \left\lfloor \frac{N}{2} \right\rfloor⌊ 
2
N
​
 ⌋ times.

Constraints
1 \leq T \leq 10001≤T≤1000
1 \leq N \leq 1001≤N≤100
SS contains only the characters 0 and 1.
Sample 1:
Input
Output
4
3
101
3
001
4
1011
6
010011
101
00
111
1001
Explanation:
Test case 11: The given string is already a palindrome.

Test case 22: Applying the operation on index i=3i=3 makes S =S= 00 which is a palindrome.

Test case 33: Applying the operation on index i=2i=2 makes S =S= 111 which is a palindrome.

Test case 44: Applying the operation on index i=1i=1 makes S =S= 10011. Then applying the operation on index i=5i=5 makes S =S= 1001 which is a palindrome.

*/

// solution 


#include<string>
#include <iostream>
using namespace std;

void solution()
{
    int n;
    string s;
    cin>>n>>s;
    int zero=0;
    int one=0;
    for(int i =0;i<n;i++)
    {
        if(s[i]=='0')
        {
            zero++;
        }
        else
        {
            one++;
        }
    }
    string ans="";
    if(zero>one)
    {
        while(zero--)
        {
            ans.push_back('0');
        }
    }
    else
    {
        while(one--)
        {
            ans.push_back('1');
        }
    }
    cout<<ans<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    solution();
	}
	return 0;
}
