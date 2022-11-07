/*
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list (ARR1).


Input format :
The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
Print the intersection elements. Each element is printed in a separate line.
Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2
*/

// solution 

#include<unordered_map>
void printIntersection(int a1[], int a2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> check;
    int *arr1=NULL;
    int *arr2=NULL;
    int a1size;
    int a2size;
    if(n>m)
      {
        arr1=a1;
        arr2=a2;
        a1size=n;
    	a2size=m;
        
    }
    else
    {
        
        arr1=a2;
        arr2=a1;
        a1size=m;
    	a2size=n;

    }
    	
    
    for(int i =0;i<a1size;i++)
    {
        if(check.count(arr1[i])>0)
       		check[arr1[i]]++;
        else
        	check[arr1[i]]=1;
        
    }
    for(int i =0;i<a2size;i++)
    {
        if(check[arr2[i]]>0)
            {
                cout<<arr2[i]<<endl;
            	check[arr2[i]]--;
        	}
            
        
    }
    
}
