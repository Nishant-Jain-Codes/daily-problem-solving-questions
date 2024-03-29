/*

Check Palindrome (recursive)
Send Feedback
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false

*/

// solution 

#include<string.h>

bool helper(char input[], int si, int ei)
{
    if(si>=ei)
    {
        return true;
    }
    if(input[si]==input[ei])
    {
        
        bool restcalc = helper(input,si+1,ei-1);
    	return restcalc;
    }
    else
    {
        return false;
    }
    
    
}


bool checkPalindrome(char input[]) {
    int len = strlen(input);
    return helper(input,0,len-1);
    
}
