/*

All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

*/

// solution 

int allIndexes(int input[], int size, int x, int output[]) {
 if(size==0)
 {
     return 0;
 }
    int a=allIndexes(input+1,size-1,x,output);
    for(int b=0;b<a;b++)
    {
        output[b]++;
    }
    if(input[0]==x)
    {
        for(int c=a-1;c>=0;c--)
        {
            output[c+1]=output[c];
        }
        output[0]=0;
        
        return 1+a;
    }
    else
    {
        return a;
    }
}
