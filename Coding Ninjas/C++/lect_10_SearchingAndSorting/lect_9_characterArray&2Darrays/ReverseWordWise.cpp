/*

Reverse Word Wise
Send Feedback
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always

*/

// solution 

#include<string.h>
#include <bits/stdc++.h>
void revhelp(char s[],int l,int r)
{int temp;
 
    while (l < r) {
        
        temp=s[r];
        s[r]=s[l];
        s[l]=temp;
        l++;
        r--;
    }
}



void reverseStringWordWise(char input[]) {
    //rev whole string ;
    revhelp(input,0,strlen(input)-1);
    //rev individual words;
    int i,count = 0;
    for(i =0;i<strlen(input);i++)
    {
		if(input[i]==' ')
        {
            
            revhelp(input,i-count,i-1);
            count=0;
        }
        else
        {
            count++;
        }
    }
    revhelp(input,i-count,i-1);
}
