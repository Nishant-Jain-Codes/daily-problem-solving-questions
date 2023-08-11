class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        return longestSubarrayWithKAtmostDistinct(fruits, 2);
    }

private:
    int longestSubarrayWithKAtmostDistinct(vector<int> &arr, int k)
    {
        unordered_map<int, int> hash;
        int i = 0, j = 0, ans = 0;
        while (j < arr.size())
        {
            hash[arr[j]]++;
            if (hash.size() <= k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (hash.size() > k)
            {
                while (hash.size() > k)
                {
                    hash[arr[i]]--;
                    if (hash[arr[i]] == 0)
                        hash.erase(arr[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};