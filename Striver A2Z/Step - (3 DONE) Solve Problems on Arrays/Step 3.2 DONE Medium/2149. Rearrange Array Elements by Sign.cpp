// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

class Solution {
public:
    /*
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int>pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0)
	            pos.push_back(arr[i]);
	       else 
	            neg.push_back(arr[i]);
	    }
	    int i=0;
	    for(auto x:pos){
	        arr[i]=x;
	        i+=2;
	    }
	     i=1;
	    for(auto x:neg){
	        arr[i]=x;
	        i+=2;
	    }
        return arr;
    }*/
    vector<int> rearrangeArray(vector<int>& nums){
    int n = nums.size();
        vector<int> ans(n, 0);
        int positiveElementIndex = 0, negativeElementIndex = 1;

        for(auto num : nums){
            if(num > 0){
                ans[positiveElementIndex] = num;
                positiveElementIndex += 2;
            }
            else if(num < 0){
                ans[negativeElementIndex] = num;
                negativeElementIndex += 2;
            }
        }
        return ans;
    }
};