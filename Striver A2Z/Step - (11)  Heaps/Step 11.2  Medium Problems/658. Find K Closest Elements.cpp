class Solution {
public:
    struct comp{
        bool operator()(pair<int,int> &p1, pair<int,int> & p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        vector<int> answer;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k){
             //   answer.push_back(pq.top().second);
                pq.pop();
            }
        }
        while(!pq.empty()){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        //sort(answer.begin(),answer.end());
        return answer;
    }
};