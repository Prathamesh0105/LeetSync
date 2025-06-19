class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int ans = 1;
        int min_val = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - min_val > k) {
                ans++;
                min_val = nums[i];
            }
        }
        return ans;
    }
};