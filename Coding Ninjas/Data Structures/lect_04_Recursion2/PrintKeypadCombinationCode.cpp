/*

Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

// solution 

#include <iostream>
#include <string>
using namespace std;
void printKeypadhelper(int num, string refrence[] , string output)
{
    if(num==0)
    {
        cout<<output<<endl;
        return ;
    }
    string ref = refrence[(num%10)-1];
    int reflen = ref.size();
    
    for(int i = 0 ; i<reflen;i++)
    {
        printKeypadhelper(num/10,refrence,ref[i]+output); 
    }
                          return ; 
}


void printKeypad(int num){
    string output = "";
    string refrence[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    printKeypadhelper(num,refrence,output);
}
