class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);//inserting length of stick at the end
        cuts.insert(cuts.begin(),0);//inserting 
        return recursion(cuts,1,c);
    }
private: 
//! confused about the base case and why k<=j
    int recursion(vector<int> & cuts , int i , int j ){
        if (i>j)
            return 0;
        int temp = INT_MAX;
        for(int k = i ; k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1];
            int leftCost = recursion(cuts,i,k-1);
            int rightCost = recursion(cuts,k+1,j);
            temp = min(temp,cost+leftCost+rightCost);
        }
        return temp;
    }
};