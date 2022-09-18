/*
https://classroom.codingninjas.com/app/classroom/me/16422/content/313158/offering/4332185/problem/625


You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
*/

// soluton

#include<bits/stdc++.h>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    map[arr[i]]++;
    int ans=0;
    if(k!=0)
    {
        for(int i=0;i<n;i++)
        {
		if(map.find(arr[i]+k)!=map.end())
        {
            ans += (map[arr[i]+k]*map[arr[i]]);
            
            map[arr[i]]=0;
        }
        }
    }
    else 
    {
        for(int i=0;i<n;i++)
        {	if(map.find(arr[i])!=map.end())
        {
                for(int j=1;j<map[arr[i]];j++)
                {
                    ans+=j;
                }
            map[arr[i]]=0;
        }
        }
    }
    return ans;
    
}
