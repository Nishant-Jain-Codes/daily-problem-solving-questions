/*

Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1

*/

// solution 

void printsubsetsumtok(int input[], int size , int k , int output[],int outsize)
{
    if(size==0)
    {
        if(k==0)
        {
            for(int i =0 ;i<outsize;i++)
            {
                cout<<output[i]<<" ";
            }cout<<endl;
         
        }
        
        return ;
    }
    
    int *temp = new int[outsize+1];
    int i; 
    for( i=0;i<outsize;i++)
    {
        temp[i]=output[i];
    }
    temp[i]=input[0];
   
    printsubsetsumtok(input+1,size-1,k-input[0],temp,outsize+1);
    printsubsetsumtok(input+1,size-1,k,output,outsize);
    
     delete []temp ;
   
}


void printSubsetSumToK(int input[], int size, int k) {
    int *output = new int[size];
    printsubsetsumtok(input,size,k,output,0);
}
