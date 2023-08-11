class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0,ans=0,i=0,j=0;
        while(j<nums.size()){
            count+= nums[j]%2==0 ? 0 : 1;
            while(i<j && count>k){
                count-=nums[i]%2==0 ? 0 : 1;
                i++;
            }
            if(count==k){
                int temp = i;
                while(temp<=j && nums[temp]%2==0){
                    temp++;
                }
                ans+=temp-i+1;
            }
            j++;
        }
        return ans;
    }
};