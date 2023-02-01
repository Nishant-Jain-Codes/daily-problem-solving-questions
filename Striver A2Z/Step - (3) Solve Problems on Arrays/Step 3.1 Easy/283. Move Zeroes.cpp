// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int zero=0;
	    int j=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0)
	           {
                    arr[j++]=arr[i];	               
	           }
	       else{
	           zero++;
	           
	       }
	    }
	    for(int i=n-1;i>=n-zero;i--)
	    {
	        arr[i]=0;
	    }
    }
};