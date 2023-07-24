//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int> numsMain(n,0);
	    for(int i=0;i<n;i++)
	        numsMain[i]=arr[i];
	   return mergeSortSolution(numsMain);
	}
private: 
vector<int> mergeSortSolution(vector<int> &numsMain)
    {
        vector<int> answer(numsMain.size(), 0);
        vector<pair<int, int>> nums;
        for (int i = 0; i < numsMain.size(); i++)
        {
            nums.push_back({numsMain[i], i});
        }

        // Helper function to perform the merge
        function<void(int, int, int)> merge = [&nums, &answer](int si, int mid, int ei)
        {
            if (si >= ei)
                return;
            vector<pair<int, int>> temp;
            int i = si;
            int j = mid + 1;
            while (i <= mid && j <= ei)
            {
                int iVal = nums[i].first;
                int iIdx = nums[i].second;
                int jVal = nums[j].first;
                int jIdx = nums[j].second;
                if (iVal > jVal)
                {
                    if (iIdx < jIdx)
                    {
                        answer[iIdx]+= (ei - j + 1);
                    }
                    temp.push_back({iVal, iIdx});
                    i++;
                }
                else
                {
                    temp.push_back({jVal, jIdx});
                    j++;
                }
            }
            while (i <= mid)
            {
                temp.push_back({nums[i].first, nums[i].second});
                i++;
            }
            while (j <= ei)
            {
                temp.push_back({nums[j].first, nums[j].second});
                j++;
            }
            for (int i = si; i <= ei; i++)
            {
                nums[i] = temp[i - si];
            }
        };

        // Merge sort using the helper function
        function<void(int, int)> mergeSort = [&nums, &mergeSort, &merge](int si, int ei)
        {
            if (si >= ei)
                return;
            int mid = (si + ei) / 2;
            mergeSort(si, mid);
            mergeSort(mid + 1, ei);
            merge(si, mid, ei);
        };

        mergeSort(0, nums.size() - 1);
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends