class Solution {
private:
    void findCombinations(int start, int sum, int k, int target, vector<vector<int>>& result, vector<int>& combination) {
        if (combination.size() == k && sum == target) {
            result.push_back(combination);
            return;
        }

        if (combination.size() > k || sum > target) return;

        for (int num = start; num <= 9; num++) {
            combination.push_back(num);
            findCombinations(num + 1, sum + num, k, target, result, combination);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        findCombinations(1, 0, k, n, result, combination);
        return result;
    }
};
