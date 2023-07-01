//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return a.second.second<b.second.second;
}
class Node{
private:
    Node* links[2];
public:
    Node(){
        links[0] = NULL;
        links[1] = NULL;
    }
    bool containsBit(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int no){
        Node* curr = root;
        for(int i=31;i>=0;i--){
            int bit = (no>>i)&1;
            if(!curr->containsBit(bit)){
                curr->put(bit,new Node());
            }
            curr = curr->get(bit);
        }
    }
    int findMaxXor(int num){
        Node* curr = root;
        int maxXor = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(curr->containsBit(1-bit)){
                maxXor += (1<<i);
                curr = curr->get(1-bit);
            }
            else{
                curr = curr->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution
{
public:
    vector<long long> maximumXor(int N, int Q, vector<int> &nums,vector<vector<int>> &queries)
    {
        // code here
        vector<long long> ans(queries.size());
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int,int>>> q;
        for(int i=0;i<queries.size();i++)
            q.push_back({i,{queries[i][0],queries[i][1]}});//{index,{x,m}}
        sort(q.begin(),q.end(),comp);
        Trie trie;
        int curIdx = 0;
        for(auto query : q){
            int idx = query.first;
            int x = query.second.first;
            int m = query.second.second;
            while(curIdx<nums.size() && nums[curIdx]<=m){
                trie.insert(nums[curIdx]);
                curIdx++;
            }
            if(curIdx==0)
                ans[idx] = -1;
            else
                ans[idx] = trie.findMaxXor(x);
        }
        return ans;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        Solution obj;
        vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends