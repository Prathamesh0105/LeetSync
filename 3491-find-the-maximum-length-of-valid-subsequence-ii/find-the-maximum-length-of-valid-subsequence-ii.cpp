class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 2;
        for (int j = 0; j < k; ++j) {
            vector<int> dp(k, 0);
            for (int i = 0; i < nums.size(); ++i) {
                int mod = nums[i] % k;
                int pos = (j - mod + k) % k;
                dp[mod] = dp[pos] + 1;
            }

            for (int val : dp) {
                res = max(res, val);
            }
        }
        return res;
    }
};