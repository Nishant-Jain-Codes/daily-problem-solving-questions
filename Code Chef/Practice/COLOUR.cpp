/*
https://www.codechef.com/submit/COLOUR?tab=statement


Problem
For the human eye, primary colours are red, green, and blue.

Combining 11 drop each of any two primary colours produces a new type of secondary colour. For example, mixing red and green gives yellow, mixing green and blue gives cyan, and, mixing red and blue gives magenta.

You have X, Y,X,Y, and ZZ drops of red, green, and blue colours respectively. Find the maximum total number of distinct colours (both primary and secondary) you can have at any particular moment.

Note: You cannot mix a secondary colour with a primary or another secondary colour to get a new type of colour.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of three space separated integers X, Y,X,Y, and ZZ, the number of drops of red, green, and blue colours respectively.
Output Format
For each test case, output on a new line the maximum total number of colours (both primary and secondary) you can have using the given primary colours.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
0 \leq X, Y, Z\leq 1000≤X,Y,Z≤100
Sample 1:
Input
Output
4
1 0 1
3 3 0
1 1 1
0 0 0
2
3
3
0
Explanation:
Test case 11: We have 11 drop each of red and blue colour. If we mix these colours, we will have magenta but no red or blue. Thus, to maximize the total number of colours, it is better that we keep the red and blue colours as it is. The maximum number of colours we can have is 22.

Test case 22: We have 33 drops each of red and green colour. We can use 11 drop each of red and green to have yellow. We still have 22 drops each of red and green left. Thus, we have 33 different types of colours now.

Test case 33: If we mix any two colours, we will loose two colours and get only one colour in return. Thus, it is best to keep all colours as it is and keep 33 different varieties of colours.

Test case 44: There are no types of colours available.
*/


// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(1)
// time complexity :  O(1)

void solution()
{
    int xyz[3];
    in(xyz,3);
    int t=0;
    sort(xyz,xyz+3,greater<int>());
    if(xyz[0]>1&&xyz[1]>1)
        {
            xyz[0]--;
            xyz[1]--;
            t++;
           
        }
         if(xyz[0]>1&&xyz[2]>1)
        {
            xyz[0]--;
            xyz[2]--;
            t++;
            
        }
         if(xyz[1]>1&&xyz[2]>1)
        {
            xyz[2]--;
            xyz[1]--;
            t++;
            
        }
        if(xyz[0]>=1)
            t++;
        if(xyz[1]>=1)
            t++;
        if(xyz[2]>=1)
            t++;
      
  
  co(t);
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
