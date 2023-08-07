class customComp{
    public : 
    //value,index
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
};
class Solution2
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        int i=0,j=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,customComp> pq;
        while(j<n){
            pq.push({arr[j],j});
            if(j-i+1<k){
                j++;
            }
            else {
                while(!pq.empty() && pq.top().second<i){
                    pq.pop();
                }
                if(pq.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(pq.top().first);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Solution2 s;
        return s.max_of_subarrays(nums.data(),nums.size(),k);
    }
};