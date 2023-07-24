class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        // Use either the mergeSortSolution or stackSolution here, not both
        // return mergeSortSolution(nums);
        return stackSolution(nums);
    }

private:
    // getting tle
    // time complexity: O(n^2)
    // space complexity: O(n)
    vector<int> stackSolution(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 0);
        stack<int> stk1, stk2;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // pop all elements (<=) the nums[i] in stk1 and push to stack 2
            while (!stk1.empty() && nums[i] <= stk1.top())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            // pop all elements (>) the nums[i] int stk2 and push to stack 1
            while (!stk2.empty() && nums[i] > stk2.top())
            {
                stk1.push(stk2.top());
                stk2.pop();
            }
            // push nums[i] to stack 1
            stk1.push(nums[i]);
            answer[i] = stk2.size();
        }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     cout << answer[i] << " ";
        // }
        return answer;
    }

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
