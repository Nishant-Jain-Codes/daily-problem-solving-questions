/*

Trim Spaces
Send Feedback
Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.
Input Format :
 String S
Output Format :
Updated string
Constraints :
1 <= Length of string S <= 10^6
Sample Input :
abc def g hi
Sample Output :
abcdefghi

*/

// solution 

void trimSpaces(char input[])
{
    int i =0;    
    int j,k;
    int count=0;
    while(input[i]!='\0')
    {
        if(input[i]==' ')
        {	
            count=0;
            j=i;
           
            
            while(input[j]==' ')
            {
                count++;
                j++;
            }
            	
        	while(count>0)
            {	k=i;
                   while(input[k]!='\0')
                   {
                   input[k]=input[k+1];
                   k++;
                   }
            count--;
           }
            
        }
        i++;
    }
}
