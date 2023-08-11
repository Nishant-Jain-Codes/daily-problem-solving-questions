//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int N, int goal)
    {
        // code here
        int i=0,j=0,count=0,ans=0;
        while(j<nums.size()){
            count+=nums[j];
            while(i<j && count>goal){
                count-=nums[i];
                i++;
            }
            if(count==goal){
                int temp=i;
                while(temp<=j && nums[temp]==0){
                    temp++;
                }
                ans+=temp-i;//adding trailing zeroes
                if(goal!=0)
                    ans++;//if the goal is zero ( it have already been counted as trailing zeroes)
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int target;
        cin >> target;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.numberOfSubarrays(arr, N, target) << endl;
    }
    return 0;
}
// } Driver Code Ends