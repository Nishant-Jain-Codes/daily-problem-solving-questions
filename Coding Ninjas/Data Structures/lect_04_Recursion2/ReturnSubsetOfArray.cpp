/*

Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

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


int subset(int input[], int size, int output[][20]) 
{
     if(size==0)
    {
		output[0][0]=0;  
        return 1;
    }
    int M = subset(input+1,size-1,output);
    for(int i =0 ; i<M;i++)
    {
        output[i+M][0]=output[i][0]+1;
    	for(int j=1;j<=output[i][0];j++)
        {
            output[i+M][j+1]=output[i][j];
        }
        output[i+M][1]=input[0];
        
	}
    return 2*M;
}
