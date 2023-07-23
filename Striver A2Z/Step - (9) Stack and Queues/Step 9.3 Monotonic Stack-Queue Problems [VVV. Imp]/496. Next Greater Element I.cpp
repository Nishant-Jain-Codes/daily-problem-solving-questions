class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return bruteForce(nums1,nums2);
        
    }
private: 
    //time : O(m*n)
    //space: O(n) 
    vector<int> bruteForce(vector<int>& nums1, vector<int>& nums2){
        auto findGreater = [&nums2](int idx) {
            int no = nums2[idx];
            for (int i = idx + 1; i < nums2.size(); i++) {
                if (nums2[i] > no)
                    return nums2[i];
            }
            return -1;
        };
        unordered_map<int,int> map;
        for(int i=0;i<nums2.size();i++){
            map[nums2[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int idx = map[nums1[i]];
            int no = findGreater(idx);
            ans.push_back(no);
        }
        return ans;
    }
};