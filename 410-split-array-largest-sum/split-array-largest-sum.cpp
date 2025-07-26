class Solution {
private:
    int solve(vector<int>& arr, int mid) {
        int cnt = 1; 
        long long sum = 0;
        for (int i : arr) {
            if (sum + i <= mid) {
                sum += (long long)i;
            } else {
                cnt++; 
                sum = (long long)i;
            }
        }
        return cnt;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            int cnt = solve(nums, mid);
            if (cnt > k) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};