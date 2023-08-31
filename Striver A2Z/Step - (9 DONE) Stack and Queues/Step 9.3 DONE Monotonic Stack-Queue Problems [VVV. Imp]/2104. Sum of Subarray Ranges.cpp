// cleaner code
class Solution {
    const int mod = 1e9 + 7;

    long long calculateSubarraySum(vector<int>& nums, bool isMinimum) {
        vector<int> leftIndices, rightIndices;
        stack<int> stk;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && (isMinimum ? nums[stk.top()] > nums[i] : nums[stk.top()] < nums[i]))
                stk.pop();
            
            leftIndices.push_back(stk.empty() ? -1 : stk.top());
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && (isMinimum ? nums[stk.top()] >= nums[i] : nums[stk.top()] <= nums[i]))
                stk.pop();
            
            rightIndices.push_back(stk.empty() ? n : stk.top());
            stk.push(i);
        }
        reverse(rightIndices.begin(), rightIndices.end());

        long long answer = 0;
        for (int i = 0; i < n; i++) {
            int leftNo = i - leftIndices[i];
            int rightNo = rightIndices[i] - i;
            answer = (answer + (static_cast<long long int>(leftNo) * rightNo * nums[i]));
        }
        return answer;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long sumMin = calculateSubarraySum(nums, true);
        long long sumMax = calculateSubarraySum(nums, false);
        return (sumMax - sumMin );
    }
};

//less cleaner code 
class Solution {
    const int mod = 1e9 + 7;
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sumMin = sumOfsubArrayMinimum(nums);
        long long sumMax = sumOfsubArrayMaximum(nums);
        return sumMax-sumMin;
    }
private: 
    long long sumOfsubArrayMinimum(vector<int>&nums){
        vector<int> leftMin,rightMin;
        stack<int> stk;
        //for leftMin
        for(int i=0;i<nums.size();i++){
            while(!stk.empty() && nums[stk.top()]> nums[i])
                stk.pop();
            leftMin.push_back(stk.empty()?-1:stk.top());
            stk.push(i);
        }
        //emptying stack to reuse
        while(!stk.empty())stk.pop();
        //for rightMin
        for(int i=nums.size()-1;i>=0;i--){
            while(!stk.empty() && nums[stk.top()]>=nums[i])
                stk.pop();
            rightMin.push_back(stk.empty()?nums.size():stk.top());
            stk.push(i);
        }
        reverse(rightMin.begin(),rightMin.end());
        //for calc subarray sum min
        long long answer = 0;
        for(int i=0;i<nums.size();i++){
            int leftNo = i-leftMin[i];
            int rightNo = rightMin[i]-i;
            answer = (answer + (static_cast<long long int>(leftNo) * rightNo * nums[i]) ) ;
        }
    return answer;
    }
     long long sumOfsubArrayMaximum(vector<int>&nums){
        vector<int> leftMax,rightMax;
        stack<int> stk;
        //for leftMax
        for(int i=0;i<nums.size();i++){
            while(!stk.empty() && nums[stk.top()]< nums[i])
                stk.pop();
            leftMax.push_back(stk.empty()?-1:stk.top());
            stk.push(i);
        }
        //emptying stack to reuse
        while(!stk.empty())stk.pop();
        //for rightMax
        for(int i=nums.size()-1;i>=0;i--){
            while(!stk.empty() && nums[stk.top()]<=nums[i])
                stk.pop();
            rightMax.push_back(stk.empty()?nums.size():stk.top());
            stk.push(i);
        }
        reverse(rightMax.begin(),rightMax.end());
        //for calc subarray sum max
        long long answer = 0;
        for(int i=0;i<nums.size();i++){
            int leftNo = i-leftMax[i];
            int rightNo = rightMax[i]-i;
            answer = (answer + (static_cast<long long int>(leftNo) * rightNo * nums[i]) ) ;
        }
        return answer;
    }
};