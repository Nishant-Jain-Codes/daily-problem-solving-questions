/*

Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
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

int getCodes(string input, string output[10000]) {
    if(input.empty())
    {
        output[0]="";
        return 1; 
    }
    
    string pf = convert(input.substr(0,1));
    int so1=getCodes(input.substr(1,input.length()-1),output);
    int i =0;
    for(;i<so1;i++)
    {
        output[i]=pf+output[i];
    }
    
    
    int no =no=(input[0]-'0')*10 + (input[1]-'0');
    string temp[10000];
    if(no>=10&&no<=26)
    {
        int so2=getCodes(input.substr(2,input.length()-1),temp);
        string pf2=convert(input.substr(0,2));
        for(int j=0;j<so2;j++)
        {
            output[i++]=pf2+temp[j];
        }
    }
    return i;
    
}

