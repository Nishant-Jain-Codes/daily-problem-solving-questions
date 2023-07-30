class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        return brute(nums);
    }
private:    
    int brute(vector<int> & nums){
        unordered_set<int> s;
        for (auto &no : nums)
            s.insert(no);
        int ans = 0;
        int unique = s.size();
        for (int si = 0; si < nums.size(); si++)
        {

            for (int len = si; len <= nums.size(); len++)
            {
                unordered_set<int> s2;
                for (int i = si; i < len; ++i)
                {
                    cout<<nums[i]<<" ";
                    s2.insert(nums[i]);
                }
                cout<<endl;
                if (s2.size() == unique)
                    ans++;
            }
        }
        return ans;
    }
};