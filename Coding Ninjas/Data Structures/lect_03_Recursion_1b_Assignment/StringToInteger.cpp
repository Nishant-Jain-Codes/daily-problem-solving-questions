/*

String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567

*/

// solution 

#include<math.h>
#include<cstring>


int stringToNumber(char input[]) {
    
	if(strlen(input)<=0)
    {
        return 0;
    }
    int recurr = stringToNumber(input+1);
    
   
    return recurr + ((int)input[0]-48)*pow(10,strlen(input)-1);
}


