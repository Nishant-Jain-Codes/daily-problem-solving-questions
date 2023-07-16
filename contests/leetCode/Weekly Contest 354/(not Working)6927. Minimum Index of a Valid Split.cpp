class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //finding leader
        int size = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<size;i++){
            m[nums[i]]++;
        }
        int leader = -1;
        for(auto it:m){
            if(it.second > size/2){
                leader = it.first;
                break;
            }
        }
        cout<<leader<<endl;
        vector<int> left(size,0);
        for(int i=0;i<size;i++){
            if(nums[i] == leader){
                if(i==0)
                    left[i] = 1;
                else
                    left[i] = left[i-1]+1;
            }
            else{
                if(i==0)
                    left[i] = 0;
                else
                    left[i] = left[i-1];
            }
        }
        for(int i=0;i<size;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        int ans = -1;
        for(int i=1;i<size-1;i++){
            int freqLeft = left[i-1];
            int freqRight = left[size-1] - left[i-1];
            int leftSize = i;
            int rightSize = size-i;
            cout<<freqLeft<<" "<<freqRight<<" "<<leftSize<<" "<<rightSize<<endl;
            if(freqLeft*2 >= leftSize && freqRight*2 >= rightSize){
                ans = i;
                break;
            }
        }
        return ans;
    }

};