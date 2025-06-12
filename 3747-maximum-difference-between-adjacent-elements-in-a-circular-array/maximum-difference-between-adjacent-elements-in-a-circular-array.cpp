class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0 ; i < nums.size() - 1 ; i++)
            maxi = max(maxi , abs(nums[i + 1] - nums[i]));
        maxi = max(maxi , abs(nums[nums.size() - 1] - nums[0]));
        return maxi;
    }
};