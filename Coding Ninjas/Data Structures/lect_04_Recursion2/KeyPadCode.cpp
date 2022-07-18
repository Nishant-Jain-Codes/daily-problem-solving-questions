/*

Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

#include <string>
using namespace std;
int keypadhelper(int num,string output[],string refrence[])
{
	if(num==0)
    {
        output[0]="";
        return 1;
    }
    int SizeOfOutput = keypadhelper(num/10,output,refrence);
    
    string ref=refrence[(num%10)-1];
    for(int i = 0; i<ref.size();i++)
    {
        for(int j=0;j<SizeOfOutput;j++)
        {
            output[j+(i*SizeOfOutput)]=output[j];
        }
    }
    for(int i = 0; i<ref.size();i++)
    {
        for(int j=0;j<SizeOfOutput;j++)
        {
            output[j+(i*SizeOfOutput)]=output[j+(i*SizeOfOutput)]+ref[i];
        }
    }
    return ref.size()*SizeOfOutput;
}


int keypad(int num, string output[])
{
	string refrence[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return  keypadhelper(num,output,refrence);
     
}
