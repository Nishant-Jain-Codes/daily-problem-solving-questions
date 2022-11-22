/*

Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 

*/

// solution 

#include<math.h>
void helper( int * input , int size , int * output,int ph)
{
    if(size==0)
    {
        for(int i =0 ; i<ph;i++)
        {
            cout<<output[i]<<" ";
        }cout<<endl;
        return ;
    }
    helper ( input+1,size-1,output,ph);
    int * newout = new int[ph+1];
    for(int i=0;i<ph;i++)
    {
        newout[i]=output[i];
    }
    newout[ph]=input[0];
    helper ( input+1,size-1,newout,ph+1);
    return ;
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    
   int *output ;
    helper(input,size,output,0);
}
