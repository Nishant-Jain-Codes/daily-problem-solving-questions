/*

Count Characters
Send Feedback
Write a program to count and print the total number of characters (lowercase english alphabets only), digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
Print count of characters, count of digits and count of white spaces respectively (separated by space).
Input Format :
A stream of characters terminated by '$'
Output Format :
3 integers i.e. count_of_characters count_of_digits count_of_whitespaces (separated by space)
Sample Input :
abc def4 5$
Sample Output :
6 2 2
Sample Output Explanation :
Number of characters : 6 (a, b, c, d, e, f)
Number of digits : 2 (4, 5)
Number of white spaces : 2 (one space after abc and one newline after 4)

*/

// solution 

#include<iostream>
using namespace std;

int main(){

   char input;
    int a=0,n=0,w=-1;
    while(input != '$')
    {
        input = cin.get();
        if((input>=65 && input<=90)||(input>=97 && input<=122))
        {
            a++;
        }
        else if(input>=48 && input<=57)
        {
            n++;
        }
        else
        {
            w++;
        }
    }
    cout<<a<<' '<<n<<' '<<w;
    return 0;
}


