/*

Minimum Length Word
Send Feedback
Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.
Input Format :
String S
Output Format :
Minimum length word
Constraints :
1 <= Length of String S <= 10^5
Sample Input 1 :
this is test string
Sample Output 1 :
is
Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a

*/

// solution 

#include <cstring>
void minLengthWord(char input[], char output[])
{
		
	int len=strlen(input);
    int si=0,ei=0;
    int min_len=len;
    int min_si=0;
    int wordlen;
    while(ei<=len)
    {
        if(ei<len && input[ei]!=' ')
        {
            ei++;
        }
        else
        {	
            wordlen=ei-si;
            if(wordlen<min_len)
            {
                min_len=wordlen;
                min_si=si;
            }
            ei++;
            si=ei;
        }
    }
    int i=0;
    int k=min_si;
    for(int j=min_len;j>0;j--)
    {
        output[i]=input[k];
        k++;
        i++;
    }

}

