/*
https://leetcode.com/problems/palindrome-number/
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int n) {
        string s1=to_string(n);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};