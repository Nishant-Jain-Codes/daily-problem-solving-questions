/*
https://practice.geeksforgeeks.org/problems/reverse-an-array/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-an-array
*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    for(int i=n-1;i>=0;i--)
	        cout<<arr[i]<<" ";
	        
	        cout<<endl;
	}
	return 0;
}