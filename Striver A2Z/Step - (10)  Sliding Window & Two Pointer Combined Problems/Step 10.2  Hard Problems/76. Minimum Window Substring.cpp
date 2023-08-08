class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> hash1(256, 0);
        vector<int> hashReq(256, 0);
        for (auto c : t)
            hashReq[c]++;
        int i = 0, j = 0, ansLen = INT_MAX,minStart = -1;
        while (j < s.length())
        {
            hash1[s[j]]++;
            j++;
            while (doesSatisfy(hash1, hashReq))
            {
                if (j - i + 1 < ansLen)
                {
                    ansLen = j - i + 1;
                    minStart = i;
                }
                hash1[s[i]]--;
                i++;
            }
        }
        if(minStart == -1) 
            return "";
        else 
            return s.substr(minStart,ansLen-1);
    }

private:
    bool doesSatisfy(vector<int> &hash1, vector<int> &minReqHash)
    {
        for (int i = 0; i < 256; i++)
        {
            if (hash1[i] < minReqHash[i])
            {
                return false;
            }
        }
        return true;
    }
};
