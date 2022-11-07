/*

Print Permutations
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Note:
You do not need to print anything, it has already been taken care of. Just implement the function.  
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba

*/

// solution 

#include <iostream>
#include <string>
using namespace std;
void printpermutations(string input,string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return ;
    }
    int size = input.size();
    for(int i = 0 ; i<size;i++)
    {
        char fc = input[i];
        string rem = input.substr(0,i)+input.substr(i+1,size-1-i);
        printpermutations(rem,fc+output);
    }
}
void printPermutations(string input)
{
	string output = "";
   printpermutations(input,output);
}
