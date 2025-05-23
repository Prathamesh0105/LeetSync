class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<long long> dp = {0, LLONG_MIN};
        for (int n : nums) {
            vector<long long> cnt = {dp[0] + n, dp[1] + n};
            cnt[1] = max(cnt[1], dp[0] + (n ^ k));
            cnt[0] = max(cnt[0], dp[1] + (n ^ k));
            dp = cnt;
        }
        return dp[0];
    }
};