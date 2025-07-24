class Solution {
public:
    int total = 0;
    int curSep = 0;
    int ans = INT_MAX;
    void cal(vector<int> &nums, vector<vector<int>> &g, vector<int> &edge, int pre, int cur, bool start) {
        if (start) curSep ^= nums[cur];
        for (auto &x: g[cur]) {
            if (x == pre) continue;
            int nxt = start;
            if ((cur == edge[0] && x == edge[1]) || (cur == edge[1] && x == edge[0])) {
                nxt = true;
            }
            cal(nums, g, edge, cur, x, nxt);
        }
    }

    int dfs(vector<int> &nums, vector<vector<int>> &g, vector<int> &edge, int pre, int cur) {
        int cnt = nums[cur];
        for (auto &x: g[cur]) {
            if (x == pre) continue;
            if ((cur == edge[0] && x == edge[1]) || (cur == edge[1] && x == edge[0])) continue;
            int child = dfs(nums, g, edge, cur, x);
            int now = total ^ curSep ^ child;
            int mn = min({now, curSep, child});
            int mx = max({now, curSep, child});
            ans = min(ans, mx - mn);
            cnt ^= child;
        }
        return cnt;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        for (auto &x: nums) total ^= x;
        for (auto &edge: edges) {
            curSep = 0;
            cal(nums, g, edge, -1, 0, false);
            dfs(nums, g, edge, -1, 0);
        }
        return ans;
    }
};