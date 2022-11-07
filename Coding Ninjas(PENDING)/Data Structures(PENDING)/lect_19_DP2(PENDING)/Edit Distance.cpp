/*

Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2

*/

// solution 

#include<bits/stdc++.h>
using namespace std;

// recursive

int editDistance_recursive(string a , string b)
{
    if(a.size()==0||b.size()==0)
    {
        return a.size()+b.size();
    }
    if(a[0]==b[0])
    {
        return editDistance_recursive(a.substr(1),b.substr(1));
    }
    else 
    {
        int aa,bb,cc;
        //delete
        aa=1+editDistance_recursive(a,b.substr(1));
        //insert
        bb=1+editDistance_recursive(a.substr(1),b);
        //swap
        cc=1+editDistance_recursive(a.substr(1),b.substr(1));
        return min(aa,min(bb,cc));
    }
}

int editDistance(string a, string b) {
	// Write your code here
    return editDistance_recursive(a,b);
}
