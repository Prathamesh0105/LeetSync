class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;

        for (int idx = 0; idx < nums.size(); idx++) {
            int num = nums[idx];

            while (!deque.empty() && deque.back() < num) {
                deque.pop_back();
            }
            deque.push_back(num);

            if (idx >= k && nums[idx - k] == deque.front()) {
                deque.pop_front();
            }

            if (idx >= k - 1) {
                res.push_back(deque.front());
            }
        }

        return res;        
    }
};