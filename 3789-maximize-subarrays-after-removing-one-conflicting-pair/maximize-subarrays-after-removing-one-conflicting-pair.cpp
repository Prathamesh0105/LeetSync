class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        for (auto& pair : conflictingPairs) {
            if (pair[1] < pair[0]) {
                std::swap(pair[0], pair[1]);
            }
        }

        std::sort(conflictingPairs.begin(), conflictingPairs.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[1] < b[1];
                  });

        int m = conflictingPairs.size();
        int max1 = 0;
        int max2 = 0;
        long long gain = 0;
        long long maxGain = 0;
        long long totalOccupied = 0;

        for (int i = 0; i < m; ++i) {
            int start = conflictingPairs[i][0];
            int base = n + 1 - conflictingPairs[i][1];
            if (i < m - 1) {
                base = conflictingPairs[i + 1][1] - conflictingPairs[i][1];
            }

            if (start > max1) {
                max2 = max1;
                max1 = start;
                gain = 0;
            } else if (start > max2) {
                max2 = start;
            }

            gain += static_cast<long long>(max1 - max2) * base;
            totalOccupied += static_cast<long long>(max1) * base;

            if (gain > maxGain) {
                maxGain = gain;
            }
        }

        long long total = static_cast<long long>(n) * (n + 1) / 2;
        return total - totalOccupied + maxGain;
    }
};