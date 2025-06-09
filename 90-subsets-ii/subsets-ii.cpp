class Solution {
public:
    void findSubsets(int idx, vector<vector<int>>& result, vector<int>& nums, vector<int>& subset) {
        if (idx == nums.size()) {
            if (find(result.begin(), result.end(), subset) == result.end()) {
                result.push_back(subset);
            }
            return;
        }


        subset.push_back(nums[idx]);
        findSubsets(idx + 1, result, nums, subset);

        subset.pop_back();
        findSubsets(idx + 1, result, nums, subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  
        vector<int> subset;
        findSubsets(0, result, nums, subset);
        return result;
    }
};
