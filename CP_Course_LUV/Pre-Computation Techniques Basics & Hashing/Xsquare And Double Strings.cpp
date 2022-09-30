/*

https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-double-strings-1/?

Problem
Xsquare got bored playing with the arrays all the time. Therefore, he has decided to play with the strings. Xsquare called a string P a "double string" if string P is not empty and can be broken into two strings A and B such that A + B = P and A = B. for eg : strings like "baba" , "blabla" , "lolo" are all double strings whereas strings like "hacker" , "abc" , "earth" are not double strings at all.

Today, Xsquare has a special string S consisting of lower case English letters. He can remove as many characters ( possibly zero ) as he wants from his special string S. Xsquare wants to know , if its possible to convert his string S to a double string or not.

Help him in accomplishing this task.

Note :

Order of the characters left in the string is preserved even after deletion of some characters.

Input :
First line of input contains a single integer T denoting the number of test cases. First and the only line of each test case contains a string S denoting Xsquare's special string.

Output :
For each test case, print "Yes" if it is possible to convert the given string to a double string. Print "No" otherwise.

Constraints :
1 ≤ T ≤ 100
1 ≤ |S| ≤ 100
String |S| consists of lower case english alphabets only.
Subtasks :
Subtask 1 : 1 ≤ T ≤ 100 , 1 ≤ |S| ≤ 26 : ( 30 pts )
Subtask 2 : 1 ≤ T ≤ 100 , 27 ≤ |S| ≤ 100 : ( 30 pts )
Subtask 3 : 1 ≤ T ≤ 100 , 1 ≤ |S| ≤ 100 : ( 40 pts )
Sample Input
5
wow
tata
a
ab
lala


Sample Output
Yes
Yes
No
No
Yes

Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
TestCase 1 : "ww" can be obtained by removing 'o' from "wow". TestCase 2 : "tata" is already a double string. TestCase 3 : "a" cannot be converted to a double string. TestCase 4 : "ab" cannot be converted to a double string. TestCase 5 : "lala" is already a double string.
*/


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)

void solution()
{
    string s;
	cin>>s;
	unordered_map<char,int> map;
	for(auto x:s)
	{
		map[x]++;
	}
	int del=0;
	for(auto x:map)
	{
		if(x.second==1)
		{
			del+=x.second;
		}
	}
	YorN(s.size()-del>0);
}//===
//CODE ENDS HERE----------------------------------------------------------------------------------------------
