/*

Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

*/

// solution 

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.size()==1)
    {
        output[0]=input[0];
        return 1;
    }
    string temp[10000];
    int index=0;
    char vh=input[0];
    int val = returnPermutations(input.substr(1,input.size()-1),temp);
    for(int i = 0 ; i<val ; i++)
    {
        string temp2 = temp[i];
        for(int j=0;j<val+1;j++)
        {
        	output[index++]= temp2.substr(0,j)+vh+temp2.substr(j+1,temp2.size()-j-1);
        }
    }
    return index;
}
