/*
Given an array of N integers. Find the first element that occurs atleast K number of times.
 

Example 1:

Input :
N = 7, K = 2
A[] = {1, 7, 4, 3, 4, 8, 7}
Output :
4
Explanation:
Both 7 and 4 occur 2 times. 
But 4 is first that occurs 2 times.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function firstElementKTime() which takes the array A[], its size N and an integer K as inputs and returns the required answer. If answer is not present in the array, return -1.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N, K <= 105
1<= A <= 106
*/

// solution 

int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int,int> helper;
        for(int i=0;i<n;i++)
        {
            if(helper.count(a[i])>0)
            {
                helper[a[i]]++;
                
            }
            else
                helper[a[i]]=1;
                    
            if(helper[a[i]]==k)
                return a[i];   
        }
        return -1;
    }
