/*

Print all Codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/

// solution 

#include <string.h>
using namespace std;
string convert(string target)
{	
    int no=0;
    string out;
    int size = target.length();
    if(size==1)
    {
        no=target[0]-'0';
       
    }
    else
    {
        no=(target[0]-'0')*10 + (target[1]-'0');
         
    }
    	
    	out = 'a'+(no-1);
        return out;
}
void helper(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return ;
    }
    string pf1 = convert(input.substr(0,1));
    helper(input.substr(1,input.length()-1),output+pf1);
    
    int no =no=(input[0]-'0')*10 + (input[1]-'0');
    
    if(no>=10&&no<=26)
    {
    
        string pf2=convert(input.substr(0,2));
        helper(input.substr(2,input.length()-1),output+pf2);
    }
}
void printAllPossibleCodes(string input) {
    helper(input,"");
}

