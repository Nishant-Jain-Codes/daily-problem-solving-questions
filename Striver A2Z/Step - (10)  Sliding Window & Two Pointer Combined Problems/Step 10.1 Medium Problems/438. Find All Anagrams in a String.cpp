class Solution
{
public:
    vector<int> findAnagrams(string txt, string word)
    {
        unordered_map<char, int> map;
        for (auto c : word)
            map[c]++;
        int i = 0, j = 0, count = map.size();
        vector<int> ans;
        while (j < txt.size())
        {
            if (map.find(txt[j]) != map.end())
            {
                map[txt[j]]--;
                if (map[txt[j]] == 0)
                    count--;
            }
            if (j - i + 1 < word.length())
                j++;
            else
            {
                if (count == 0)
                    ans.push_back(i);
                if (map.find(txt[i]) != map.end())
                {
                    map[txt[i]]++;
                    if (map[txt[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};