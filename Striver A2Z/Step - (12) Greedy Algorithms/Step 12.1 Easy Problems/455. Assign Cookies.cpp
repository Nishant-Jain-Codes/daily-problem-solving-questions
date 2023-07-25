class Solution {
public:
    // Time Complexity: O(nlogn)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int happyhappyhappy = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childIdx = 0;
        int cookieIdx = 0;
        while(childIdx<g.size() && cookieIdx<s.size()){
            if(g[childIdx]<=s[cookieIdx]){
                happyhappyhappy++;
                childIdx++;
                cookieIdx++;
            }
            else{
                cookieIdx++;
            }
        }
        return happyhappyhappy;
    }
};