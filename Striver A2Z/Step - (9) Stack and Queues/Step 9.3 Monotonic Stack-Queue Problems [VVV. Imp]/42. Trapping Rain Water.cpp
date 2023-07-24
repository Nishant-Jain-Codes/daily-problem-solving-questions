class Solution
{
public:
    int trap(vector<int> &height)
    {
        return monotonicStackSolution(height);
        return twoPointerSolution(height);
        return prefixSumSolution(height);
    }

private:
    // time complexity: O(n)
    // space complexity: O(n)
    int prefixSumSolution(vector<int> &height)
    {
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        for (int i = 0; i < n; i++)
        {
            leftMax[i] = i == 0 ? height[i] : max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            rightMax[i] = i == n - 1 ? height[i] : max(rightMax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(1)
    int twoPointerSolution(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int lMax = 0;
        int rMax = 0;
        int ans = 0;
        while (l != r)
        {
            if (height[l] <= height[r])
            {
                if (lMax <= height[l])
                {
                    lMax = height[l];
                }
                else
                {
                    ans += lMax - height[l];
                }
                                    l++;
            }
            else
            {
                if (rMax <= height[r])
                {
                    rMax = height[r];
                }
                else
                {
                    ans += rMax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
    int monotonicStackSolution(vector<int> &height)
    {
        stack<int> stk; // storing index
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            while (!stk.empty() && height[stk.top()] < height[i])
            {
                int top = stk.top();
                stk.pop();
                if (!stk.empty())
                {
                    int distance = i - stk.top() - 1;
                    int maxleft = height[stk.top()];
                    int maxRight = height[i];
                    int curHeight = height[top];
                    int heightDifference = min(maxleft, maxRight) - curHeight;
                    int waterTrapped = distance * heightDifference;
                    ans += waterTrapped;
                }
            }
            stk.push(i);
        }
        return ans;
    }
};