class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int streak = 0, maxStreak = 0;
        for (int num : nums) {
            if (num == maxVal) {
                streak++;
                if (streak > maxStreak) maxStreak = streak;
            } else {
                streak = 0;
            }
        }
        return maxStreak;
    }
};