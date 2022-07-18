/*

Reverse Each Word
Send Feedback
Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
Sample Input 2:
Always indent your code
Sample Output 2:
syawlA tnedni ruoy edoc

*/

// solution 

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


void reverseEachWord(char input[]) {
     int count = 0;
    int i;
    int len=strlen(input);
    for( i =0;i<len;i++)
    {	//count ++;
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
