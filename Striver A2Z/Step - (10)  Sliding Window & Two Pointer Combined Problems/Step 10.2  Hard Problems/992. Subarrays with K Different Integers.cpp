class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return approach_2(nums, k);
        return approach_1(nums, k);
    }
private:
    // O(N)
    int atMostK(vector<int> &nums, int k) {
    if (k <= 0)
        return 0;
    unordered_map<int, int> m;
    int i = 0, j = 0, ans = 0;
    
    while (j < nums.size()) {
        m[nums[j]]++;
        j++;
        while (m.size() > k) {
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
        if (m.size() <= k) {
            ans += (j - i);
        }
    }
    return ans;
}

    int approach_2(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    // tle O(N^2)
    int approach_1(vector<int> &nums, int k){
        unordered_map<int, int> m;
        int i = 0, j = 0, ans = 0;

        while (j < nums.size())
        {
            m[nums[j]]++;

            if (m.size() < k)
            {
                j++;
            }
            else if(m.size() > k)
            {
                while (m.size() > k)
                {
                    m[nums[i]]--;
                    if (m[nums[i]] == 0)
                        m.erase(nums[i]);
                    i++;
                }
            }
            
            if(m.size() == k)
            {
                unordered_map<int, int> temp = m;
                int tempi = i;

                while (tempi <= j && temp.size() == k)
                {
                    temp[nums[tempi]]--;
                    if (temp[nums[tempi]] == 0)
                        temp.erase(nums[tempi]);
                    tempi++;
                }

                ans += (tempi - i);

                j++;
            }
            
        }

        return ans;
    }
};
