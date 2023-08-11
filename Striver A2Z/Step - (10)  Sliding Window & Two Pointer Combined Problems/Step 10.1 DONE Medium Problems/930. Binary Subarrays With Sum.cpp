class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0,count=0,ans=0;
        while(j<nums.size()){
            count+=nums[j];
            while(i<j && count>goal){
                count-=nums[i];
                i++;
            }
            if(count==goal){
                int temp=i;
                while(temp<=j && nums[temp]==0){
                    temp++;
                }
                ans+=temp-i;//adding trailing zeroes
                if(goal!=0)
                    ans++;//if the goal is zero ( it have already been counted as trailing zeroes)
            }
            j++;
        }
        return ans;
    }
};