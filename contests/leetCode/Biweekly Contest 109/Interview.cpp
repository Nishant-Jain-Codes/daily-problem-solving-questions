class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> vowelMap;
        string ans = s;
        for (auto c : s) {
            if (isVowel(c)) {
                vowelMap[c]++;
            }
        }
        vector<char> order = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        int vIdx = 0;
        for (auto &c : ans) {
            while (vIdx < order.size() && vowelMap[order[vIdx]] == 0) {
                vIdx++;
            }
            if (isVowel(c)) {
                c = order[vIdx]; // Use 'c' instead of 'vowelMap[c]-1'
                vowelMap[c]--;
            }
        }
        return ans;
    }

private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
