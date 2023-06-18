class Solution {
private:
    bool tabulation(int N, vector<int>& arr, int sum) {
        int sum1 = 201*101;
        vector<bool> prev(sum1 + 1, false), curr(sum1 + 1, false);
        prev[0] = true;
        curr[0] = true;
        prev[arr[0]] = true;
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= sum; j++) {
                bool notTake = prev[j];
                bool take = false;
                if (j - arr[i] >= 0)
                    take = prev[j - arr[i]];
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }

public:
    bool canPartition(vector<int>& arr) {
        if (arr.empty()) {
            return false;
        }
        int N = arr.size();
        int Sum = 0;
        for (int i = 0; i < N; i++) {
            Sum += arr[i];
        }
        if (Sum % 2 != 0) {
            return false;
        }
        Sum /= 2;
        return tabulation(N, arr, Sum);
    }
};
