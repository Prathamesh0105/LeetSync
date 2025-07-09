class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int res = 0;
        vector<int> sum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + (endTime[i] - startTime[i]);
        }

        for (int i = k - 1; i < n; ++i) {
            int right = (i == n - 1) ? eventTime : startTime[i + 1];
            int left = (i == k - 1) ? 0 : endTime[i - k];
            int freeTime = right - left - (sum[i + 1] - sum[i - k + 1]);
            res = max(res, freeTime);
        }

        return res;
    }
};