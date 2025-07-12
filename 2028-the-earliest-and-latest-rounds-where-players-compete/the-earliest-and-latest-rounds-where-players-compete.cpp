class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = min(firstPlayer, secondPlayer);
        int right = max(firstPlayer, secondPlayer);

        // If they are mirror positions — they meet in first round
        if (left + right == n + 1) {
            return {1, 1};
        }

        // For base cases
        if (n == 3 || n == 4) {
            return {2, 2};
        }

        // Mirror for symmetry if closer to right
        if (left - 1 > n - right) {
            int temp = n + 1 - left;
            left = n + 1 - right;
            right = temp;
        }

        int nextRound = (n + 1) / 2;
        int minRound = n, maxRound = 1;

        if (right * 2 <= n + 1) {
            // Case 1: Players are both in the left half
            int preLeft = left - 1;
            int midGap = right - left - 1;

            for (int i = 0; i <= preLeft; ++i) {
                for (int j = 0; j <= midGap; ++j) {
                    auto res = earliestAndLatest(nextRound, i + 1, i + j + 2);
                    minRound = min(minRound, 1 + res[0]);
                    maxRound = max(maxRound, 1 + res[1]);
                }
            }
        } else {
            // Case 2: Players are in opposite halves
            int mirrored = n + 1 - right;
            int preLeft = left - 1;
            int midGap = mirrored - left - 1;
            int innerGap = right - mirrored - 1;

            for (int i = 0; i <= preLeft; ++i) {
                for (int j = 0; j <= midGap; ++j) {
                    int pos1 = i + 1;
                    int pos2 = i + j + 1 + (innerGap + 1) / 2 + 1;
                    auto res = earliestAndLatest(nextRound, pos1, pos2);
                    minRound = min(minRound, 1 + res[0]);
                    maxRound = max(maxRound, 1 + res[1]);
                }
            }
        }

        return {minRound, maxRound};
    }
};