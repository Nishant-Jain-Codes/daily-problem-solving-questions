/*
Problem Statement
Given a string that represents a roman number. Convert the roman number to an integer and return it.
Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M.
Table Of Values:
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For Example:
3 is written as III in Roman numeral, just three ones added together. 13 is written as XIII, which is simply X + III. The number 25 is written as XXV, which is XX + V 
Note:
Do not print anything, just return an integer denoting the equivalent integer of the given roman number

It is guaranteed that the string input is one of the characters of I, V, X, L, C, D, M.

It is guaranteed that the integer value of the given roman number will not exceed 3999.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘T’ lines represent the ‘T’ test cases.

The first line of each test case contains a string ‘roman’ representing the number's roman number representation.
Output Format
For each test case, return a single integer denoting the integer value of the given roman number.
Constraints:
1 <= T <= 50
1 <= roman.length <= 15

Time limit: 1 second
Sample Input 1:
3
XII
XXVII
LX
Sample Output 1:
12
27
60
Explanation For Sample Input 1 :
Test Case 1:

We know that ‘X’ is 10 and we have 2 ‘I’ after it. Therefore the number is 12

Test Case 2: 

We know that ‘X’ is 10 and ‘V’ is 5 and we have 2 ‘I’ after it. Therefore the number is 20+5+2=27

Test Case 3:

We see that ‘L’ is 50 and ‘X’ is 10 so the number is 50 +10 =60
Sample Input 2:
2
XC
MM
Sample Output 2:
90
2000


*/

// solution 

int romanToInt(string s) {
    // Write your code here
    if(s.empty())
    {
        return 0;
    }
     int data;
    switch(s[0])
    {
        case 'I':data=1;break;
        case 'V':data=5;break;
        case 'X':data=10;break;
        case 'L':data=50;break;    
        case 'C':data=100;break;
        case 'D':data=500;break;
        case 'M':data=1000;break;
        default :data=0;break;
    }
    int count=1;
    while(s[0]==s[count])
    {
        count++;
    };
    int smallans = romanToInt(s.substr(count,s.length()));
   data*=count;
    if(data>=smallans)
    {
        return smallans+data;
    }
    else
    {
        return smallans-data;
    }
}
