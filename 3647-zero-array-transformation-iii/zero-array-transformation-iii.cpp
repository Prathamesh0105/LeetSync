class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> assigned;
        int count = 0;

        for (int time = 0, k = 0; time < nums.size(); time++) {
            while (!assigned.empty() && assigned.top() < time)
                assigned.pop();
            while (k < queries.size() && queries[k][0] <= time) 
                available.push(queries[k++][1]);
            while (assigned.size() < nums[time] && 
                  !available.empty() && available.top() >= time) {
                assigned.push(available.top());
                available.pop();
                count++;
            }
            if (assigned.size() < nums[time])
                return -1;
        }
        return queries.size() - count;
    }
};