// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/


bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        } 
        return p1.second<p2.second;
    }
class Solution {
public:
    

    void helperFunc(TreeNode* root, map<int, vector<pair<int, int>>>& m, int curVlevel, int curHlevel) {
        if (root == nullptr) {
            return;
        }

        if (m.find(curVlevel) != m.end()) {
            m[curVlevel].push_back({root->val, curHlevel});
        } else {
            m[curVlevel] = {{root->val, curHlevel}};
        }
        helperFunc(root->right, m, curVlevel + 1, curHlevel + 1);
        helperFunc(root->left, m, curVlevel - 1, curHlevel + 1);
        
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        map<int, vector<pair<int, int>>> m;
        helperFunc(root, m, 0, 0);

        for (auto& x : m) {
            vector<pair<int, int>>& curPair = x.second;
            sort(curPair.begin(), curPair.end(),comp);

            vector<int> curLevel;
            for (auto& y : curPair) {
                curLevel.push_back(y.first);
            }

            answer.push_back(curLevel);
        }

        return answer;
    }
};
